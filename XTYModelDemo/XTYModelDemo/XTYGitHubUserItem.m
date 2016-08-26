//
//  XTYGitHubUserItem.m
//  XTYModelDemo
//
//  Created by Michael on 16/8/26.
//  Copyright © 2016年 Michael. All rights reserved.
//

#import "XTYGitHubUserItem.h"

@implementation XTYGitHubFollower
@end

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