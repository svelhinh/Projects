//
//  APIController.swift
//  d04
//
//  Created by Sergio VELHINHO on 6/15/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit

class APIController
{
    weak var delegate : APITwitterDelegate?
    let token : String
    
    init(delegate : APITwitterDelegate?, token : String)
    {
        self.delegate = delegate
        self.token = token
    }
    
    func doTwitterRequest(pattern : String)
    {
        let CONSUMER_KEY = "2OWBq0WettmBhNm8f962wCdxM"
        let CONSUMER_SECRET = "yRI2K7HZ0CsxrzxvsbC5QeJOQkhd84Vn0bQIoZIGHjhByVeXfc"
        let BEARER = ((CONSUMER_KEY + ":" + CONSUMER_SECRET).data(using: String.Encoding.utf8)!.base64EncodedString(options: NSData.Base64EncodingOptions(rawValue : 0)))
        
        let url = NSURL(string : "https://api.twitter.com/oauth2/token")
        let request = NSMutableURLRequest(url: url as! URL)
        
        request.httpMethod = "POST"
        request.setValue("Basic " + BEARER, forHTTPHeaderField: "Authorization")
        request.setValue("application/x-www-form-urlenconded;charset=UTF-8", forHTTPHeaderField: "Content-Type")
        request.httpBody = "grant_type=client_credentials".data(using: String.Encoding.utf8)
        
        let task = URLSession.shared.dataTask(with: request as URLRequest)
        {
            (data, response, error) in
            print(response ?? "")
            if error != nil
            {
                print(error ?? "")
            }
            else if let d = data
            {
                do
                {
                    if let dic : NSDictionary = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSDictionary
                    {
                        print(dic)
                    }
                }
                catch (let err)
                {
                    print(err)
                }
            }
        }
        
        task.resume()
    }
}
