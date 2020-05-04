//
//  ViewController.swift
//  ex02
//
//  Created by Sergio VELHINHO on 6/8/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var Result: UILabel!
    
    var numberOfDigitsOnScreen:UInt = 0
    var maxNumberOnScreen:UInt = 15
    
    @IBAction func Numbers(_ sender: UIButton)
    {
        if numberOfDigitsOnScreen <= maxNumberOnScreen
        {
            if Result.text == "0"
            {
                if sender.tag != 0
                {
                    Result.text = String(sender.tag)
                    numberOfDigitsOnScreen = strlen(Result.text)
                }
            }
            else
            {
                Result.text = Result.text! + String(sender.tag)
                numberOfDigitsOnScreen = strlen(Result.text)
            }
            print(sender.tag)
        }
    }

    @IBAction func Buttons(_ sender: UIButton) {
        print(sender.titleLabel!.text!)
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

