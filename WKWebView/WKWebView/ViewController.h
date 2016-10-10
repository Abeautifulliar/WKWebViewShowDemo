//
//  ViewController.h
//  WKWebView
//
//  Created by etouch on 16/10/10.
//  Copyright © 2016年 EL. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@interface ViewController : UIViewController<
WKNavigationDelegate,
WKUIDelegate,
UIGestureRecognizerDelegate
>

@property (nonatomic, strong) WKWebView *webView;

@end

