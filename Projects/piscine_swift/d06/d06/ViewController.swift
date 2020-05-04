//
//  ViewController.swift
//  d06
//
//  Created by Sergio VELHINHO on 6/20/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit
import CoreMotion

class ViewController: UIViewController {
    
    static var animator : UIDynamicAnimator?
    static let itemBehaviour = UIDynamicItemBehavior()
    static let gravity = UIGravityBehavior()
    static let collisions = UICollisionBehavior()
    var motionManager = CMMotionManager()
    var motionQueue = OperationQueue()
    
    func activateGravity()
    {
        ViewController.gravity.magnitude = 3

        ViewController.animator?.addBehavior(ViewController.gravity)
    }
    
    func activateCollisions()
    {
        ViewController.collisions.translatesReferenceBoundsIntoBoundary = true
        ViewController.animator?.addBehavior(ViewController.collisions)
    }
    
    func activatePhysicsProperties()
    {
        ViewController.itemBehaviour.elasticity = 0.6
        ViewController.animator?.addBehavior(ViewController.itemBehaviour)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        ViewController.animator = UIDynamicAnimator(referenceView: view)
        
        activateGravity()
        activateCollisions()
        activatePhysicsProperties()
    }
    
    func addShape(_ coord : CGPoint)
    {
        let shapeInst = Shape(coord)

        view.addSubview(shapeInst)
        
        ViewController.gravity.addItem(shapeInst)
        ViewController.collisions.addItem(shapeInst)
        ViewController.itemBehaviour.addItem(shapeInst)
    }
    
    @IBAction func tapAction(_ sender: UITapGestureRecognizer) {
        addShape(sender.location(in: view))
    }

}

