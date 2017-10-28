//
//  ImagesViewController.swift
//  d03
//
//  Created by Sergio VELHINHO on 6/15/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit

class ImagesViewController: UIViewController, UIScrollViewDelegate {

    var imageView : UIImageView?
    var image : UIImage?
    
    @IBOutlet weak var imageScrollView: UIScrollView!

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        
        imageView = UIImageView(image: image)
        imageScrollView.addSubview(imageView!)
        imageScrollView.contentSize = (imageView?.frame.size)!
        imageScrollView.maximumZoomScale = 100
    }
    
    override func viewDidLayoutSubviews() {
        imageScrollView.minimumZoomScale = imageScrollView.bounds.width / (imageView?.bounds.width)!
    }
    
    func viewForZooming(in scrollView: UIScrollView) -> UIView? {
        return imageView
    }

}
