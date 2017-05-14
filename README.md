# XTYModel
A light weight and high performance model framework for iOS.

# Main features
 *  Support all basic object you would need and object types can be automatically converted.
 * All data types will be verified to ensure type-safe during the conversion process.
 * Model class do not inherit from any other base class.
 * This library contains only 4 files.

# Requirements
* iOS 7.0+ 
* Xcode 7.11+

# Installation
## CocoaPods
 * Add pod 'XTYModel' to your Podfile
 * Run `pod install` or `pod update`
 * Import `<XTYModel/XTYModelItem.h>`

## Framework
* add XTYModel.framework to your project
* import "XTYModelItem.h"


# API
## XTYJson

```
/** jsonObj is NSDictionary or NSArray*/
@property(nonatomic, readonly) id jsonObj;

/**  init method*/
- (instancetype)initWithObject:(id)object;
+ (XTYJson *)jsonWithObject:(id)obj;
+ (XTYJson *)jsonWithData:(NSData*)jsonData;
+ (XTYJson *)jsonWithString:(NSString*)jsonStr;

/**  get json value with key*/
- (XTYJson*)jsonForKey:(NSString*)key;

/** get json value with index*/
- (XTYJson*)jsonAtIndex:(NSUInteger)index;
```

## XTYModelItem
```

/**
 *  the raw data properties, readonly. When we parse the properties, the item retains the original data, this data can use to upload to the server or anyother uses.
 */
@property (nonatomic, readonly) NSDictionary* originDict;
@property (nonatomic, readonly) XTYJson *json;

/**
 *  init method, the input data is a XTYJson instance, if your original data is a dictionary, just use the XTYJson init method to get a instance with your dictionary. We do not encourage to use original data class, like NSDictionary or NSArray to init item.
 */
- (instancetype)initWithJson:(XTYJson*)json;
- (instancetype)initwithDictionary:(NSDictionary *)dictionary;

/**
 *  follow methods use to parse list data structure, they are class method and should be used with subClass
 */
+ (NSArray<__kindof XTYModelItem *> *)arrayWithArrayDictionary:(NSArray<NSDictionary *>*)arrayDict;
+ (NSMutableArray<__kindof XTYModelItem *> *)mutableArrayWithArrayDictionary:(NSArray<NSDictionary *>*)arrayDict;

#pragma mark - config methods,rewrite them in the subClass if you need
/**
 *  the map between json key and property key <NSString* -> NSString*>, if the key return from the server is not same as the property name, you can rewrite this method to make the properties parse correctly
 */
+ (NSDictionary *)JSONKeyMapForProperties;

/**
 *  returen a dictionary, if the property is kind of NSArray instance or inherite from it, the key is the property name<NSString *>, the value is the Class <like [NSString class]>
 */
+ (NSDictionary *)elementClassMapForNSArrayProperties;

```


# Usage 
## Match model property to different JSON key

```
// json data - gitHub_user
{
    "login": "facebook",
    "userID": 69631,
    "avatar_url": "https://avatars.githubusercontent.com/u/69631?v=3",
    "gravatar_id": "",
    "url": "https://api.github.com/users/facebook",
    "html_url": "https://github.com/facebook",
    "followers_list": [
                       {
                       "userID":777,
                       "url":"https://api.github.com/users/facebook/followers"
                       },
                       {
                       "userID":777,
                       "url":"https://api.github.com/users/facebook/followers"
                       }
                       ,
                       {
                       "userID":777,
                       "url":"https://api.github.com/users/facebook/followers"
                       }
                    ],
    "following_url": "https://api.github.com/users/facebook/following{/other_user}
    "public_repos": 147,
    "public_gists": 12,
    "followers": 3,
    "following": 0
}

```

##Model Item

```
@interface XTYGitHubFollower : XTYModelItem

@property (nonatomic, assign) NSInteger userID;
@property (nonatomic, strong) NSString *url;

@end

@interface XTYGitHubUserItem : XTYModelItem

@property (nonatomic, strong) NSString *login;
@property (nonatomic, assign) NSInteger userID;
@property (nonatomic, strong) NSString *avatar_url;
@property (nonatomic, strong) NSString *gravatar_id;
@property (nonatomic, strong) NSString *url;
@property (nonatomic, strong) NSString *html_url;
@property (nonatomic, strong) NSArray<XTYGitHubFollower *> *followers_list;
@property (nonatomic, strong) NSString *following_url;
@property (nonatomic, assign) NSInteger publicRepos;
@property (nonatomic, assign) NSInteger publicGists;
@property (nonatomic, assign) NSInteger followers;
@property (nonatomic, assign) NSInteger following;

@end
```
- **note that  `followers_list` is an array which contains `XTYGitHubFollower` instance, and `publicRepos and publicGists `are not equal to the json key. So we should make some mapping operation through rewrite super class methods**

```
@implementation XTYGitHubUserItem

+ (NSDictionary *)JSONKeyMapForProperties
{
    return @{@"publicRepos":@"public_repos",
             @"publicGists":@"public_gists"};
}

+ (NSDictionary *)elementClassMapForNSArrayProperties
{
    return @{@"followers_list":[XTYGitHubFollower class]};
}

@end
```

##parse json data with XTYGitHubUserItem

```
NSString *filePath = [[NSBundle mainBundle] pathForResource:@"gitHub_user" ofType:@"json"];
XTYJson *git_user_json = [XTYJson jsonWithData:[NSData dataWithContentsOfFile:filePath]];
XTYGitHubUserItem *userItem = [[XTYGitHubUserItem alloc] initWithJson:git_user_json];
```



#License
XTYModel is released under the MIT license. See LICENSE for details.
