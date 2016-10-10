# WKWebViewShowDemo
WKWebView打开外部应用 链接 替换JS alert confirm示例
####WKWebView出于安全性考虑, 对于打开外部链接 应用等操作进行了拦截
#####WKWebView打开外部应用, Safari等
#####设置代理
```
_webView.navigationDelegate = self;
```
#####手动打开拦截
```
- (void)webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler{
    // WKWebView默认拦截scheme 需在下面方法手动打开
    // 打开外部应用 Safari等操作
    if ([navigationAction.request.URL.absoluteString hasPrefix:@"xxx"]) { // 对应的scheme
        [[UIApplication sharedApplication] openURL:navigationAction.request.URL];
    }
    decisionHandler(WKNavigationActionPolicyAllow);
}
```
#####WKWebView替换JS alert confirm等
######设置代理
```
_webView.UIDelegate = self;
```
#####拦截JS alert
```
- (void)webView:(WKWebView *)webView runJavaScriptAlertPanelWithMessage:(NSString *)message initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(void))completionHandler{
    // WKWebView不支持JS的alert 用此方法进行拦截
    // message为JS中alert显示的信息 可与前端开发约定好信息
    if ([message isEqualToString:@"xxx"]) {
        // 做OC操作
    }
    completionHandler();
}
```
######拦截JS confirm
```
- (void)webView:(WKWebView *)webView runJavaScriptConfirmPanelWithMessage:(NSString *)message initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(BOOL result))completionHandler{
    // 类比alert 拦截JS confirm
    completionHandler(NO);
}
```