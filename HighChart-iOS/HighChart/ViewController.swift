//
//  ViewController.swift
//  HighChart
//
//  Created by Truptimayee Sahoo on 16/11/22.
//

import UIKit
import Highcharts

class ViewController: UIViewController {
    
    var chartView: MYTHighChartView!
    override func viewDidLoad() {
        super.viewDidLoad()
        let chartView = MYTHighChartView(frame: CGRect(x: 50, y: 100, width: 600, height: 600))
        self.view.addSubview(chartView)
        chartView.configureGraph()
    }
    
}

class MYTHighChartView: UIView {
    var chartView: HIChartView!
    
    override func draw(_ rect: CGRect) {
        super.draw(rect)
    }
    public override init(frame: CGRect) {
        super.init(frame: frame)
        commonInit()
    }
    required public init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        commonInit()
    }
    private func commonInit() {
        chartView = HIChartView(frame: frame)
        self.addSubview(chartView)
    }
}

extension MYTHighChartView {
   
    
    func configureGraph() {
        let options = HIOptions()
        options.chart = chart()
        options.title = title()
        options.xAxis = [xAxis()]
        options.yAxis = [yAxis()]
        options.credits = credit()
        options.exporting = exporting()
        options.series = [series()]
        options.plotOptions = plotOptions()
        options.tooltip = tooltip()
        options.legend = legend()
        options.accessibility = HIAccessibility()
        options.accessibility.landmarkVerbosity = "false"
        chartView.lang = lang()
        chartView.options = options
    }
    
    func chart() -> HIChart {
        let chart = HIChart()
        //        chart.type = "column"
        //        chart.zoomType = "x" //depricated
       /**
         //2. Not working below code
         chart.events = HIEvents()
         chart.events.selection = HIFunction(closure: { context in
         guard let context = context,
         let min = context.getProperty("event.xAxis[0].min"),
         let max = context.getProperty("event.xAxis[0].max")
         else { return }
         
         print("min: \(min) and max \(max)")
         }, properties: ["context.xAxis[0].min", "context.xAxis[0].max"])
        */
        return chart
    }
    
    func title() -> HITitle {
        let title = HITitle()
        title.align = "left"
        title.text = "Kwh"
        return title
    }
    
    func xAxis() -> HIXAxis {
        let xAxis = HIXAxis()
        xAxis.categories = [ "April", "May", "June", "July", "Aug", "Sep" ]
        return xAxis
    }
    
    func yAxis() -> HIYAxis {
        let yaxis = HIYAxis()
        yaxis.gridLineDashStyle = "longdash"
        yaxis.title = HITitle()
        yaxis.title.text = ""
        yaxis.labels = HILabels()
        yaxis.labels.style = HICSSObject()
        yaxis.labels.style.color = "rgb(0, 0, 255)"
        yaxis.labels.style.fontSize = "20px"
        yaxis.labels.x = -5
        yaxis.min = 0.0
        yaxis.max = 18.0
        yaxis.tickInterval = 6
        yaxis.allowDecimals = 1
        return yaxis
    }
    
    func credit() -> HICredits {
        let credit = HICredits()
        credit.enabled = false
        return credit
    }
    
    func exporting() -> HIExporting {
        let exporting = HIExporting()
        exporting.enabled = false
        return exporting
    }
    
    func tooltip() -> HITooltip {
        let tooltip = HITooltip()
        tooltip.enabled = false
        return tooltip
    }
    
    func legend() -> HILegend {
        let legend = HILegend()
        legend.enabled = false
        return legend
    }
    
    func series() -> HISeries {
        let series = HISeries()
        series.data = [17.9, 16.2, 15.3, 0, 13.84, 12]
        series.type = "column"
        
        series.allowPointSelect = true
        series.states = HIStates()
        series.states.select = HISelect()
        series.states.select.color = HIColor(uiColor: .yellow)
        
        series.accessibility = HIAccessibility()
        series.accessibility.point = HIPoint()
        series.accessibility.point.descriptionFormatter = HIFunction(jsFunction: "function (point) { return ` ${point.category}:  ${point.y} kilo watt hour` }"
        )
        
        /** How can Voice over reads as selected when particular bar is selected
         */
        return series
    }
    
    func plotOptions() -> HIPlotOptions {
        let plotOptions = HIPlotOptions()
        plotOptions.series = HISeries()
        plotOptions.series.point = HIPoint()
        plotOptions.series.point.events = HIEvents()
        
        let clickFunction = HIFunction(closure: { context in
            guard let context = context else { return }
            
            let category = context.getProperty("this.category") ?? "",
                value = context.getProperty("this.y") ?? ""
            let alertMessage = "Category: \(category), value: \(value)"
            print(alertMessage)
    /**
     1.How can I get minX, minY, maxX, maxY from this tap event
     */

        }, properties: ["this.category", "this.y"])
        
        plotOptions.series.point.events.click = clickFunction

        return plotOptions
    }

    func lang() -> HILang {
        let lang = HILang()
        lang.accessibility = HIAccessibility()
        lang.accessibility.axis = HIAxis()
        lang.accessibility.axis.xAxisDescriptionSingular = ""
        lang.accessibility.axis.yAxisDescriptionSingular = ""
        lang.accessibility.chartTypes = HIChartTypes()
        lang.accessibility.chartTypes.columnSingle = "bar chart header"// Focus is not proper
        lang.accessibility.table = HITable()
        lang.accessibility.table.viewAsDataTableButtonText = ""
        lang.accessibility.defaultChartTitle = "defaultChartTitle" //Not working
        return lang
    }
}
