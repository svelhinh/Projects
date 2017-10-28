//
//  ViewController.swift
//  ex04
//
//  Created by Sergio VELHINHO on 6/8/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var Result: UILabel!
    
    var numberOnScreen:Int = 0
    var numberOfDigitsOnScreen:UInt = 0
    var maxNumberOnScreen:UInt = 15
    var previousNumber:Int = 0
    var operation = 0
    var calcul = false
    var divByZero = false
    
    func ShowNumber(_ tag: Int, _ add: Bool)
    {
        if calcul || add
        {
            Result.text = String(tag)
            numberOfDigitsOnScreen = strlen(Result.text)
            numberOnScreen = Int(Result.text!)!
            if (calcul)
            {
                calcul = false
            }
        }
        else
        {
            Result.text = Result.text! + String(tag)
            numberOfDigitsOnScreen = strlen(Result.text)
            numberOnScreen = Int(Result.text!)!
        }
    }
    
    @IBAction func Numbers(_ sender: UIButton)
    {
        if (divByZero)
        {
            divByZero = false
        }
        if numberOfDigitsOnScreen <= maxNumberOnScreen || calcul
        {
            if Result.text == "0"
            {
                if sender.tag != 0
                {
                    ShowNumber(sender.tag, true)
                }
            }
            else
            {
                ShowNumber(sender.tag, false)
            }
            print(sender.tag)
        }
    }
    
    func DoOperation(_ op: Int)
    {
        switch op {
        case 12: // /
            if (numberOnScreen != 0)
            {
                Result.text = String(previousNumber / numberOnScreen)
                previousNumber = Int(Result.text!)!
            }
            else
            {
                Result.text = "Division by 0"
                previousNumber = 0
                numberOnScreen = 0
                operation = 0
                calcul = false
                divByZero = true
            }
            break
        case 13: // *
            Result.text = String(previousNumber &* numberOnScreen)
            previousNumber = Int(Result.text!)!
            break
        case 14: // -
            Result.text = String(previousNumber &- numberOnScreen)
            previousNumber = Int(Result.text!)!
            break
        case 15: // +
            Result.text = String(previousNumber &+ numberOnScreen)
            previousNumber = Int(Result.text!)!
            break
        default:
            break
        }
    }

    func CheckOp(_ op: Int)
    {
        switch op {
        case 12: // /
            if (operation != 0)
            {
                DoOperation(op)
            }
            break
        case 13: // *
            if (operation != 0)
            {
                DoOperation(op)
            }
            break
        case 14: // -
            if (operation != 0)
            {
                DoOperation(op)
            }
            break
        case 15: // +
            if (operation != 0)
            {
                DoOperation(op)
            }
            break
        default:
            break
        }
    }
    
    @IBAction func Buttons(_ sender: UIButton) {
        if Result.text != "" && sender.tag != 10 && sender.tag != 11 && sender.tag != 16
        {
            if (operation == 0)
            {
                previousNumber = (divByZero ? 0 : Int(Result.text!)!)
                CheckOp(sender.tag)
            }
            else
            {
                CheckOp(operation)
            }
            operation = sender.tag
            calcul = true
        }
        else if sender.tag == 10
        {
            Result.text = "0"
            previousNumber = 0
            numberOnScreen = 0
            operation = 0
            calcul = false
        }
        else if sender.tag == 11
        {
            if operation != 0 && calcul
            {
                numberOnScreen = 0
            }
            numberOnScreen *= -1
            Result.text = String(numberOnScreen)
        }
        else if sender.tag == 16
        {
            DoOperation(operation)
            calcul = false
        }
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

