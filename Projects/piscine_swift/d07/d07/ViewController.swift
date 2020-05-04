//
//  ViewController.swift
//  d07
//
//  Created by Sergio VELHINHO on 6/21/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit
import RecastAI
import ForecastIO

class ViewController: UIViewController {
    
    @IBOutlet weak var requestLabel: UILabel!
    @IBOutlet weak var textField: UITextField!
    
    var bot : RecastAIClient?
    let client = DarkSkyClient(apiKey: "351faf7053088256450f8c030fa885f2")
    var click = false
    
    func successHandler(response : Response) {
        print(response.sentiment!)
        
//        requestLabel?.text = response.sentiment
        textField.text! = ""
        recastRequestDone(response)
        click = false
    }
    
    func failureHandler(error : Error) {
        print(error)
//        requestLabel?.text = "Error"
        textField.text! = ""
        recastRequestFails(error)
        click = false
    }
    
    @IBAction func makeRequestButton(_ sender: Any) {
        if !click
        {
            click = true
            if textField.text != ""
            {
                self.bot = RecastAIClient(token : "05e1fe9de985a92a17a5effcccff7632")
                
                self.bot?.textRequest(textField.text!, successHandler: successHandler(response: ), failureHandle: failureHandler(error: ))
            }
            else
            {
                click = false
                requestLabel.text = "Error"
            }
        }
    }
    
    func recastRequestDone(_ response : Response)
    {
        let location = response.get(entity: "location")
        
        print(location?["lng"] as Any)
        
        if location != nil
        {
            client.getForecast(latitude: location?["lat"] as! Double, longitude: location?["lng"] as! Double) { result in
                switch result {
                case .success(let currentForecast, let requestMetadata):
                    self.requestLabel?.text = currentForecast.daily?.summary!
                case .failure(let error):
                    self.requestLabel?.text = "Error"
                }
            }
        }
        else
        {
            self.requestLabel?.text = "Error"
        }
    }
    
    func recastRequestFails(_ error : Error)
    {
        requestLabel?.text = "Error"
    }

}

