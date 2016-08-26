//
//  XTYGitHubUserItem.h
//  XTYModelDemo
//
//  Created by Michael on 16/8/26.
//  Copyright © 2016年 Michael. All rights reserved.
//

#import "XTYModelItem.h"

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