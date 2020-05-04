//: Playground - noun: a place where people can play

import UIKit

let CUSTOMER_KEY = "c741675bf1d086ed85857599992941cb27d4a61744b6e5691597f8e0bc647414"
let CUSTOMER_SECRET = "1c4887d31bbcf4fbdb7fa649d7fcc1f73072eb39001acec6eb7718a8c73b152e"
let BEARER = ((CUSTOMER_KEY + ":" + CUSTOMER_SECRET).data(using: String.Encoding.utf8))!.base64EncodedString(options: NSData.Base64EncodingOptions(rawValue: 0))

let url = URL(string: "https://api.intra.42.fr/oauth/token")
var request = URLRequest(url: url!)
request.httpMethod = "POST"
request.setValue("client_credentials", forHTTPHeaderField: "grant_type")
request.setValue(CUSTOMER_KEY, forHTTPHeaderField: "client_id")
request.setValue(CUSTOMER_SECRET, forHTTPHeaderField: "client_secret")
request.httpBody = String("grant_type=client_credentials&client_id=" + CUSTOMER_KEY + "&client_secret=" + CUSTOMER_SECRET)?.data(using: String.Encoding.utf8)

let task = URLSession.shared.dataTask(with: request)
{
    (data, response, error) in
    print(response ?? "")
    if let err = error
    {
        print (error ?? "")
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
            print (err)
        }
    }
}

task.resume()