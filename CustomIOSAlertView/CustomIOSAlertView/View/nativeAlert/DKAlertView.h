//
//  CustomIOSAlertView.h
//  CustomIOSAlertView
//
//  Created by Richard on 20/09/2013.
//  Copyright (c) 2013-2015 Wimagguc.
//
//  Lincesed under The MIT License (MIT)
//  http://opensource.org/licenses/MIT
//

#import <UIKit/UIKit.h>

/* lzy注170815：
 代理以及必须的实现的方法。
 */
@protocol CustomIOSAlertViewDelegate
/* lzy注170815：
 回传对象自身：alertView
 多个按钮，回传被点击的按钮的索引。
 */
- (void)customIOS7dialogButtonTouchUpInside:(id)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;

@end

/* lzy注170815：
 继承自UIView，遵守alertView代理
 */
@interface DKAlertView : UIView<CustomIOSAlertViewDelegate>
/* lzy注170815：
 这个弹窗添加到的父视图
 */
@property (nonatomic, retain) UIView *parentView;    // The parent view this 'dialog' is attached to
/* lzy注170815：
 弹窗的容器视图
 */
@property (nonatomic, retain) UIView *dialogView;    // Dialog's container view
/* lzy注170815：
 弹窗的内容容器视图
 */
@property (nonatomic, retain) UIView *containerView; // Container within the dialog (place your ui elements here)
/* lzy注170815：
 弹窗的delegate
 */
@property (nonatomic, assign) id<CustomIOSAlertViewDelegate> delegate;
/* lzy注170815：
 弹窗上按钮的title数组
 */
@property (nonatomic, retain) NSArray *buttonTitles;
/* lzy注170815：
 是否使用UIInterpolatingMotionEffect（垂直和水平两个方向上使用，iOS7+的API）
 
 UIInterpolatingMotionEffect对象，映射了开发者指定的水平和垂直倾斜角度的值，因此UIKit可以把这些配置应用于开发者的视图上。
 
 You use this class to determine the amount of tilt along a single axis to apply to a view.
 After creating an instance of this class, you must assign appropriate values to the minimumRelativeValue and maximumRelativeValue properties. As the user moves the device, the motion effect object translates the fixed offset values returned by the system (which are in the range -1 to 1) to the range of values you specified. UIKit then applies the translated values to any target views.
 Availability	iOS (7.0 and later), tvOS (7.0 and later)
 
 在
 
 */
@property (nonatomic, assign) BOOL useMotionEffects;
/* lzy注170815：
 在弹窗外点击，是否关闭弹窗
 */
@property (nonatomic, assign) BOOL closeOnTouchUpOutside;       // Closes the AlertView when finger is lifted outside the bounds.
/* lzy注170815：
 block属性。
 无返回值，参数是alertView和被点击按钮的索引
 */
@property (copy) void (^onButtonTouchUpInside)(DKAlertView *alertView, int buttonIndex) ;

- (id)init;

/*!
 DEPRECATED: Use the [CustomIOSAlertView init] method without passing a parent view.
 */
- (id)initWithParentView: (UIView *)_parentView __attribute__ ((deprecated));

- (void)show;
- (void)close;
/* lzy注170815：
 作者写了个预留给IB使用Action
 */
- (IBAction)customIOS7dialogButtonTouchUpInside:(id)sender;
/* lzy注170815：
 上面block属性的setter
 */
- (void)setOnButtonTouchUpInside:(void (^)(DKAlertView *alertView, int buttonIndex))onButtonTouchUpInside;
/* lzy注170815：
 设备转屏将触发的方法
 */
- (void)deviceOrientationDidChange: (NSNotification *)notification;
- (void)dealloc;

@end
