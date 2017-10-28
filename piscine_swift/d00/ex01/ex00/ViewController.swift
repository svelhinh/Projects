//
//  ViewController.swift
//  ex00
//
//  Created by Sergio VELHINHO on 6/8/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var HelloWorld: UILabel!

    @IBAction func PrintHello(_ sender: Any) {
        HelloWorld.text = "Hello World!"
        print("Hello World!")
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

