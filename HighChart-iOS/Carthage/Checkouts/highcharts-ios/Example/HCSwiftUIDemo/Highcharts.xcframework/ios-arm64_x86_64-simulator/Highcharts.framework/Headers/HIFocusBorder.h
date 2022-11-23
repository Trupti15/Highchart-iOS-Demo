/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HICSSObject.h"


/**
Options for the focus border drawn around elements while navigating through them.

**Try it**

* [Custom focus ring](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/accessibility/custom-focus)
*/
@interface HIFocusBorder: HIChartsJSONSerializable

/**
Focus border margin around the elements.

**Defaults to** `2`.
*/
@property(nonatomic, readwrite) NSNumber *margin;
/**
Style options for the focus border drawn around elements while navigating through them. Note that some browsers in addition draw their own borders for focused elements. These automatic borders cannot be styled by Highcharts. In styled mode, the border is given the `.highcharts-focus-border` class.
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
Enable/disable focus border for chart.

**Defaults to** `True`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Hide the browser's default focus indicator.

**Defaults to** `True`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *hideBrowserFocusOutline;

-(NSDictionary *)getParams;

@end
