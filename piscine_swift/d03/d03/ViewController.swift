//
//  ViewController.swift
//  d03
//
//  Created by Sergio VELHINHO on 6/14/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UICollectionViewDataSource, UICollectionViewDelegate {
    
    let reuseIdentifier = "cell" // also enter this string as the cell identifier in the storyboard
    var items = ["https://assets.letemps.ch/sites/default/files/media/2017/06/03/file6v66p10odvl1d0g2r93z.jpg", "https://s-media-cache-ak0.pinimg.com/originals/a3/b0/ac/a3b0acc7fd85878fa4f69367a8be354f.jpg", "https://www.nasa.gov/sites/default/files/styles/full_width_feature/public/thumbnails/image/dbbpp4vxoae-z42.jpg", "https://eoimages.gsfc.nasa.gov/images/imagerecords/82000/82227/klyuchevskaya_oli_2013293_lrg.jpg"]
    
    
    // tell the collection view how many cells to make
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int
    {
        return items.count
    }
    
    func switchNetworkActivityMonitor()
    {
        if UIApplication.shared.isNetworkActivityIndicatorVisible
        {
            UIApplication.shared.isNetworkActivityIndicatorVisible = false
        }
        else
        {
            UIApplication.shared.isNetworkActivityIndicatorVisible = true
        }
    }
    
    
    func showAlert(msg : String)
    {
        let alertController = UIAlertController(title: "Error", message: msg, preferredStyle: .alert)
        
        let okAction = UIAlertAction(title: "OK", style: .default, handler: nil)
        
        alertController.addAction(okAction)
        
        self.present(alertController, animated: true, completion: nil)
    }
    
    // make a cell for each cell index path
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell
    {
        // get a reference to our storyboard cell
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: self.reuseIdentifier, for: indexPath as IndexPath) as! MyCollectionViewCell
        
        let qos = DispatchQoS.default.qosClass
        
        let queue = DispatchQueue.global(qos: qos)
        
        queue.async {
            DispatchQueue.main.async {
                self.switchNetworkActivityMonitor()
            }
            // Use the outlet in our custom class to get a reference to the UILabel in the cell
            if let url = NSURL(string: self.items[indexPath.item])
            {
                if let data = NSData(contentsOf: url as URL) {
                    DispatchQueue.main.async {
                        cell.imageView.image = UIImage(data: data as Data)
                    }
                }
                else
                {
                    self.showAlert(msg: "Cannot access to " + self.items[indexPath.item])
                    cell.imageExists = false
                }
            }
            else
            {
                self.showAlert(msg: "Cannot access to " + self.items[indexPath.item])
                cell.imageExists = false
            }

            DispatchQueue.main.async {
                cell.activityMonitor.stopAnimating()
                cell.activityMonitor.isHidden = true
                self.switchNetworkActivityMonitor()
            }
        }
        
        return cell
    }
    
    override func shouldPerformSegue(withIdentifier identifier: String, sender: Any?) -> Bool {
        if identifier == "imageSegue"
        {
            if let cell = sender as? MyCollectionViewCell
            {
                return cell.imageExists
            }
        }
        return true
    }
    
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "imageSegue"
        {
            if let vc = segue.destination as? ImagesViewController
            {
                if let cell = sender as? MyCollectionViewCell
                {
                    vc.image = cell.imageView.image
                }
            }
        }
    }
}
