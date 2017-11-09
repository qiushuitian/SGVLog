//
//  SGVLogger.h
//  SGVLog
//
//  Created by jian deng on 19/10/2017.
//  Copyright © 2017 jian deng. All rights reserved.
//

#import <Foundation/Foundation.h>

/// debug级别的log输出的通知
extern NSString * SGVLogNotification;

/** SGV Log配置
 */
@interface SGVLogConfig : NSObject
// 来源类型:1-app;2-联网SDK;3-广告SDK;4-日志收集SDK
@property(nonatomic) NSInteger srcType;
/// 各个业务端自己的客户端版本code
@property(nonatomic) NSInteger versionCode;
/// 各个业务端自己的客户端版本名称
@property(nonatomic, copy) NSString * versionName;
/// 各个业务端自己的唯一标示,如app端的deviceCode
@property(nonatomic, copy) NSString * bCode;
/// 是否为调试版本
@property(nonatomic) BOOL isDebug;

@end

@interface SGVLogger : NSObject

/** loger系统初始化，请在应用程序初始化的时候调用此方法，
 如 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions 中。
 */
+(void)startLogger;

/** log sdk 的版本号
 */
+(NSString *)sdkVersion;

/** 初始化相应模块的loger
 */
+(SGVLogger *)loggerWithConfig:(SGVLogConfig *)config;

/** 记录info级别的log
 */
-(void)logInfo:(NSString *)key content:(NSString *)format, ...;

/** 记录debug级别的log。debug级别的log在debug模式下会打印到控制台上
 */
-(void)logDebug:(NSString *)key content:(NSString *)format, ...;

/** 记录warning级别的log。
 */
-(void)logWarning:(NSString *)key content:(NSString *)format, ...;

/** 记fatal级别的log。此种log会立即上报服务器
 */
-(void)logFatal:(NSString *)key content:(NSString *)format, ...;


@end
