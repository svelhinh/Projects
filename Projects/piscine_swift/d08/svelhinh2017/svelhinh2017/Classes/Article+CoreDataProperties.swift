//
//  Article+CoreDataProperties.swift
//  
//
//  Created by Sergio VELHINHO on 6/22/17.
//
//  This file was automatically generated and should not be edited.
//

import Foundation
import CoreData


extension Article {

    @nonobjc public class func fetchRequest() -> NSFetchRequest<Article> {
        return NSFetchRequest<Article>(entityName: "Article");
    }

    @NSManaged public var title: String?
    @NSManaged public var content: String?
    @NSManaged public var language: String?
    @NSManaged public var image: NSData?
    @NSManaged public var creationDate: NSDate?
    @NSManaged public var modificationDate: NSDate?
    
    public override var description: String {
        return "\(title),  \(content), \(language), \(image), \(creationDate), \(modificationDate)"
    }

}
