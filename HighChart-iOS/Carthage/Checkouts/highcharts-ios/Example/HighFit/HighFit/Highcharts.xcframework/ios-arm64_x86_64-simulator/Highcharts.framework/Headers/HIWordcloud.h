/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HIRotation.h"
#import "HIColor.h"
#import "HICSSObject.h"


/**
 A `wordcloud` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `wordcloud` series are defined in `plotOptions.wordcloud`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        wordcloud: {
            // shared options for all wordcloud series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'wordcloud'
    }]
 });
 <pre>
 */
@interface HIWordcloud: HISeries

/**
When using automatic point colors pulled from the global `colors` or series-specific `plotOptions.column.colors` collections, this option determines whether the chart should receive one color per series or one color per point. In styled mode, the `colors` or `series.colors` arrays are not supported, and instead this option gives the points individual color class names on the form `highcharts-color-{n}`.

**Defaults to** `True`.

**Try it**

* [False by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-false/)
* [True](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *colorByPoint;
/**
CSS styles for the words.

**Defaults to** `{"fontFamily":"sans-serif", "fontWeight": "900"}`.
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
A threshold determining the minimum font size that can be applied to a word.

**Defaults to** `1`.
*/
@property(nonatomic, readwrite) NSNumber *minFontSize;
/**
The word with the largest weight will have a font size equal to this value. The font size of a word is the ratio between its weight and the largest occuring weight, multiplied with the value of maxFontSize.

**Defaults to** `25`.
*/
@property(nonatomic, readwrite) NSNumber *maxFontSize;
/**
Spiral used for placing a word after the initial position experienced a collision with either another word or the borders. It is possible for users to add their own custom spiralling algorithms for use in word cloud. Read more about it in our [documentation](https://www.highcharts.com/docs/chart-and-series-types/word-cloud-series#custom-spiralling-algorithm)

**Defaults to** `rectangular`.
*/
@property(nonatomic, readwrite) NSString *spiral;
/**
The width of the border surrounding each column or bar. Defaults to `1` when there is room for a border, but to `0` when the columns are so dense that a border would cover the next column. In styled mode, the stroke width can be set with the `.highcharts-point` rule.

**Try it**

* [2px black border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-borderwidth/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
Rotation options for the words in the wordcloud.

**Try it**

* [Word cloud with rotation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/wordcloud-rotation)
*/
@property(nonatomic, readwrite) HIRotation *rotation;
/**
This option decides which algorithm is used for placement, and rotation of a word. The choice of algorith is therefore a crucial part of the resulting layout of the wordcloud. It is possible for users to add their own custom placement strategies for use in word cloud. Read more about it in our [documentation](https://www.highcharts.com/docs/chart-and-series-types/word-cloud-series#custom-placement-strategies)

**Defaults to** `center`.
*/
@property(nonatomic, readwrite) NSString *placementStrategy;
/**
Padding between each column or bar, in x axis units.

**Defaults to** `0.1`.

**Try it**

* [0.1 by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-pointpadding-default/)
* [0.25](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-pointpadding-025/)
* [0 for tightly packed columns](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-pointpadding-none/)
*/
@property(nonatomic, readwrite) NSNumber *pointPadding;
/**
The corner radius of the border surrounding each column or bar.

**Try it**

* [Rounded columns](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-borderradius/)
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
The X axis range that each point is valid for. This determines the width of the column. On a categorized axis, the range will be 1 by default (one category unit). On linear and datetime axes, the range will be computed as the distance between the two closest data points. The default `null` means it is computed automatically, but this option can be used to override the automatic value. This option is set by default to 1 if data sorting is enabled.

**Try it**

* [Set the point range to one day on a data set with one week between the points](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-pointrange/)
*/
@property(nonatomic, readwrite) NSNumber *pointRange;
/**
The minimal height for a column or width for a bar. By default, 0 values are not shown. To visualize a 0 (or close to zero) point, set the minimal point length to a pixel value like 3\. In stacked column charts, minPointLength might not be respected for tightly packed values.

**Try it**

* [Zero base value](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-minpointlength/)
* [Positive and negative close to zero values](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-minpointlength-pos-and-neg/)
*/
@property(nonatomic, readwrite) NSNumber *minPointLength;
/**
The spacing between columns on the Z Axis in a 3D chart.

**Defaults to** `1`.
*/
@property(nonatomic, readwrite) NSNumber *groupZPadding;
/**
A series specific or series type specific color set to apply instead of the global `colors` when `colorByPoint` is true.
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;
/**
The color of the border surrounding each column or bar. In styled mode, the border stroke can be set with the `.highcharts-point` rule.

**Defaults to** `#ffffff`.

**Try it**

* [Dark gray border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-bordercolor/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
3D columns only. The color of the edges. Similar to `borderColor`, except it defaults to the same color as the column.
*/
@property(nonatomic, readwrite) HIColor *edgeColor;
/**
When `true`, the columns will center in the category, ignoring null or missing points. When `false`, space will be reserved for null or missing points.

**Try it**

* [Center in category](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-column/centerincategory/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *centerInCategory;
/**
The maximum allowed pixel width for a column, translated to the height of a bar in a bar chart. This prevents the columns from becoming too wide when there is a small number of points in the chart.

**Try it**

* [Limited to 50](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-maxpointwidth-20/)
*/
@property(nonatomic, readwrite) NSNumber *maxPointWidth;
/**
A pixel value specifying a fixed width for each column or bar point. When set to `undefined`, the width is calculated from the `pointPadding` and `groupPadding`. The width effects the dimension that is not based on the point value. For column series it is the hoizontal length and for bar series it is the vertical length.

**Try it**

* [20px wide columns regardless of chart width or the amount of data points](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-pointwidth-20/)
*/
@property(nonatomic, readwrite) NSNumber *pointWidth;
/**
Padding between each value groups, in x axis units.

**Defaults to** `0.2`.

**Try it**

* [0.2 by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-grouppadding-default/)
* [No group padding - all columns are evenly spaced](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-grouppadding-none/)
*/
@property(nonatomic, readwrite) NSNumber *groupPadding;
/**
3D columns only. The width of the colored edges.

**Defaults to** `1`.
*/
@property(nonatomic, readwrite) NSNumber *edgeWidth;
/**
Depth of the columns in a 3D column chart.

**Defaults to** `25`.
*/
@property(nonatomic, readwrite) NSNumber *depth;
/**
Whether to group non-stacked columns or to let them render independent of each other. Non-grouped columns will be laid out individually and overlap each other.

**Defaults to** `true`.

**Try it**

* [Grouping disabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-grouping-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *grouping;

-(NSDictionary *)getParams;

@end
