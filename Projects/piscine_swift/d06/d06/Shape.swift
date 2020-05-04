//
//  Shape.swift
//  d06
//
//  Created by Sergio VELHINHO on 6/20/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit

class Shape: UIView {

    var width : CGFloat = 100
    var height : CGFloat = 100
    var form : eShape = eShape.Square
    
    var firstX : CGFloat?
    var firstY : CGFloat?
    
    var panGesture = UIPanGestureRecognizer()
    
    override var collisionBoundsType: UIDynamicItemCollisionBoundsType {
        switch form {
        case .Circle:
            return .ellipse
        default:
            return .rectangle
        }
    }
    
    init(_ coord : CGPoint) {
        let shape = CGRect(x: coord.x - width / 2, y: coord.y - height / 2, width: width, height: height)
        
        super.init(frame: shape)

        backgroundColor = randomColor()
        
        let random = Int(arc4random_uniform(UInt32(eShape.MAX.hashValue)))
        
        if random == eShape.Circle.hashValue
        {
            layer.cornerRadius = width / 2
            form = eShape.Circle
        }
        

        isUserInteractionEnabled = true
        
        // Drag & Drop
        panGesture = UIPanGestureRecognizer(target: self, action: #selector(dragged(_:)))

        addGestureRecognizer(panGesture)

        
        // Scale
        let scaleGesture = UIPinchGestureRecognizer(target: self, action: #selector(pinched(_:)))
        
        addGestureRecognizer(scaleGesture)
        

        // Rotation
        let rotationGesture = UIRotationGestureRecognizer(target: self, action: #selector(rotated(_:)))
        
        addGestureRecognizer(rotationGesture)
    }
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }
    
    func dragged(_ dragGesture :UIPanGestureRecognizer){
        bringSubview(toFront: self)
        let locationInSuperView = panGesture.translation(in: self.superview)
        
        switch dragGesture.state {
        case .began:
            firstX = self.center.x
            firstY = self.center.y
            ViewController.gravity.removeItem(self)
        case .changed:
            self.center.x = firstX!+locationInSuperView.x
            self.center.y = firstY!+locationInSuperView.y
            ViewController.animator?.updateItem(usingCurrentState: self)
        case .ended:
            ViewController.gravity.addItem(self)
            ViewController.animator?.updateItem(usingCurrentState: self)
        default:
            break
        }
    }
    
    func pinched(_ pinchGesture : UIPinchGestureRecognizer)
    {
        switch pinchGesture.state {
        case .changed:
            let scale = (pinchGesture.view?.layer.bounds.size.height)! * pinchGesture.scale
            if scale < 300 && scale > 60 {
                pinchGesture.view?.layer.bounds.size.height *= pinchGesture.scale
                pinchGesture.view?.layer.bounds.size.width *= pinchGesture.scale
                if let tmp = pinchGesture.view! as? Shape {
                    if (tmp.form == eShape.Circle)
                    {
                        pinchGesture.view!.layer.cornerRadius *= pinchGesture.scale
                    }
                }
                pinchGesture.scale = 1
            }
        case .ended:
            ViewController.gravity.removeItem(pinchGesture.view!)
            ViewController.collisions.removeItem(pinchGesture.view!)
            ViewController.itemBehaviour.removeItem(pinchGesture.view!)
            ViewController.gravity.addItem(pinchGesture.view!)
            ViewController.collisions.addItem(pinchGesture.view!)
            ViewController.itemBehaviour.addItem(pinchGesture.view!)
        default: ()
        }
    }
    
    func rotated(_ rotationGesture : UIRotationGestureRecognizer)
    {
        switch rotationGesture.state {
        case .changed:
                rotationGesture.view?.transform = (rotationGesture.view?.transform.rotated(by: rotationGesture.rotation))!
                rotationGesture.rotation = 0.0
        case .ended:
            ViewController.gravity.removeItem(rotationGesture.view!)
            ViewController.collisions.removeItem(rotationGesture.view!)
            ViewController.itemBehaviour.removeItem(rotationGesture.view!)
            ViewController.gravity.addItem(rotationGesture.view!)
            ViewController.collisions.addItem(rotationGesture.view!)
            ViewController.itemBehaviour.addItem(rotationGesture.view!)
        default: ()
        }
    }
}
