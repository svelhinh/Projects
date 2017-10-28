//
//  ArticleManager.swift
//  svelhinh2017
//
//  Created by Sergio VELHINHO on 6/22/17.
//  Copyright © 2017 CocoaPods. All rights reserved.
//

import Foundation
import CoreData

public class ArticleManager
{
    public var context : NSManagedObjectContext
    
    
    public init(_ context : NSManagedObjectContext) {
        self.context = context
    }

    public func newArticle(_ title: String, _ content: String, _ language: String, _ image: NSData, _ created_at: NSDate, _ updated_at: NSDate) -> Article {
        let entity = NSEntityDescription.insertNewObject(forEntityName: "Article", into: context) as! Article
        
        entity.setValue(title, forKey: "title")
        entity.setValue(content, forKey: "content")
        entity.setValue(language, forKey: "language")
        entity.setValue(image, forKey: "image")
        entity.setValue(created_at, forKey: "creationDate")
        entity.setValue(updated_at, forKey: "modificationDate")
        
        return entity
    }
    
    public func getAllArticles() -> [Article] {
        let articleFetch = NSFetchRequest<NSFetchRequestResult>(entityName: "Article")
        
        do {
            let fetchedArticles = try context.fetch(articleFetch) as! [Article]
            return fetchedArticles
            
        } catch {
            fatalError("Failed to fetch articles: \(error)")
        }
    }
    
    public func getArticles(withLang lang: String) -> [Article] {
        var matchedArticles: [Article] = []
        
        let articleFetch = NSFetchRequest<NSFetchRequestResult>(entityName: "Article")
        
        do {
            let fetchedArticles = try context.fetch(articleFetch) as! [Article]
            for article in fetchedArticles {
                if article.language == lang {
                    matchedArticles.append(article)
                }
            }
            
        } catch {
            fatalError("Failed to fetch articles: \(error)")
        }
        return matchedArticles
    }
    
    public func getArticles(containString str: String) -> [Article] {
        var matchedArticles: [Article] = []
        let articleFetch = NSFetchRequest<NSFetchRequestResult>(entityName: "Article")
        
        do {
            let fetchedArticles = try context.fetch(articleFetch) as! [Article]
            for article in fetchedArticles {
                if article.content?.lowercased().range(of: str) != nil {
                    matchedArticles.append(article)
                }
            }
            
        } catch {
            fatalError("Failed to fetch articles: \(error)")
        }
        
        return matchedArticles
    }
    
    public func removeArticle(article: Article) {
        context.delete(article)
    }
    
    public func save() {
        do {
            try context.save()
        } catch {
            fatalError("Failure to save context: \(error)")
        }
    }
}
