//
//  ViewController.swift
//  d02
//
//  Created by Sergio VELHINHO on 6/13/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {

    @IBOutlet weak var tableView: UITableView!
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return Data.people.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "peopleCell") as! PeopleTableViewCell
        
        cell.people = Data.people[indexPath.row]
        return cell
    }
    
    
    @IBAction func unWindSegue(segue: UIStoryboardSegue) {
        
    }

    override func viewWillAppear(_ animated: Bool) {
//        tableView.reloadData()
        tableView.rowHeight = UITableViewAutomaticDimension
        tableView.estimatedRowHeight = 140.0
    }
    
//    override func viewDidLoad() {
//        super.viewDidLoad()
//        // Do any additional set up after loading the view
//        
//        tableView.estimatedRowHeight = 200.0
//        tableView.rowHeight = UITableViewAutomaticDimension
//    }
//    
//    override func viewDidAppear(_ animated: Bool ) {
//        tableView.reloadData()
//    }
    
}

