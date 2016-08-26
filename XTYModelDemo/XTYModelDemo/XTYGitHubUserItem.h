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
@property (nonatomic, strong) NSString *gists_url;
@property (nonatomic, strong) NSString *starred_url;
@property (nonatomic, strong) NSString *subscriptions_url;
@property (nonatomic, strong) NSString *organizations_url;
@property (nonatomic, strong) NSString *repos_url;
@property (nonatomic, strong) NSString *events_url;
@property (nonatomic, strong) NSString *received_events_url;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, assign) BOOL site_admin;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *company;
@property (nonatomic, strong) NSString *blog;
@property (nonatomic, strong) NSString *location;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *hireable;
@property (nonatomic, strong) NSString *bio;
@property (nonatomic, assign) NSInteger publicRepos;
@property (nonatomic, assign) NSInteger publicGists;
@property (nonatomic, assign) NSInteger followers;
@property (nonatomic, assign) NSInteger following;

@end