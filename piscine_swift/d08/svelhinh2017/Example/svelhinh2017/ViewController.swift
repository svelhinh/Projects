//
//  ViewController.swift
//  svelhinh2017
//
//  Created by svelhinh on 06/22/2017.
//  Copyright (c) 2017 svelhinh. All rights reserved.
//

import UIKit
import CoreData
import svelhinh2017

@available(iOS 10.0, *)
class ViewController: UIViewController {
    
    let context = (UIApplication.shared.delegate as! AppDelegate).persistentContainer.viewContext
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let image = UIImage(named: "location")
        let imageData = (UIImagePNGRepresentation(image!) as NSData?)!
        let date = Date()
        
        let artm = ArticleManager(context)
        // Do any additional setup after loading the view, typically from a nib.
        artm.newArticle("article1", "content1", "fr", imageData, date as NSDate, date as NSDate)
        artm.newArticle("article1", "content1", "en", imageData, date as NSDate, date as NSDate)
        artm.newArticle("article2", "content2", "fr", imageData, date as NSDate, date as NSDate)
        let article = artm.newArticle("article3", "content3", "en", imageData, date as NSDate, date as NSDate)
        artm.newArticle("article4", "content3", "fr", imageData, date as NSDate, date as NSDate)
        
        
        artm.save()
        
        for art in artm.getAllArticles()
        {
            print(art.description)
        }
        
        for art in artm.getArticles(withLang: "en")
        {
            print(art.description)
        }
        
        for art in artm.getArticles(containString: "article1")
        {
            print(art.description)
        }
        
        artm.removeArticle(article: article)
        
        artm.save()
        
        for art in artm.getAllArticles()
        {
            print(art.description)
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}

