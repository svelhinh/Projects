//
//  FirstViewController.swift
//  d05
//
//  Created by Sergio VELHINHO on 6/19/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class FirstViewController: UIViewController, MKMapViewDelegate, CLLocationManagerDelegate {

    @IBOutlet weak var mapView: MKMapView!

    var locationManager = CLLocationManager()
    var annotations : [MKPointAnnotation] = []
    static var indexLoc = 0
    var lastIndexLoc = -1
    
    func addAnnotation(_ coord : CLLocationCoordinate2D, _ title : String = "Title", _ subtitle : String = "Subtitle")
    {
        let annotation = MKPointAnnotation()
        annotation.coordinate = coord
        annotation.title = title
        annotation.subtitle = subtitle
        
        
        annotations.append(annotation)
        mapView.addAnnotation(annotation)
    }
    
    func zoomToCoord(_ coord : CLLocationCoordinate2D, _ zoom : MKCoordinateSpan = MKCoordinateSpanMake(0.01, 0.01))
    {
        let span = MKCoordinateSpanMake(0.01, 0.01)
        
        let region = MKCoordinateRegion(center: coord, span: span)
        mapView.setRegion(region, animated: false)
    }

    @IBAction func segmentedControlAction(_ sender: UISegmentedControl) {
        switch (sender.selectedSegmentIndex) {
        case 0:
            mapView.mapType = .standard
        case 1:
            mapView.mapType = .satellite
        default:
            mapView.mapType = .hybrid
        }
    }

    @IBAction func geolocButton(_ sender: Any) {
        locationManager.requestWhenInUseAuthorization()
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyNearestTenMeters
        locationManager.distanceFilter = 10
        locationManager.startUpdatingLocation()
        mapView.setUserTrackingMode(MKUserTrackingMode.follow, animated: true)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        if FirstViewController.indexLoc != lastIndexLoc
        {
            zoomToCoord(annotations[FirstViewController.indexLoc].coordinate)
            lastIndexLoc = FirstViewController.indexLoc
        }
    }
    
    override func viewDidLoad() {
        for loc in Locations.locs {
            addAnnotation(loc.coord, loc.title, loc.subtitle)
        }
    }


}

