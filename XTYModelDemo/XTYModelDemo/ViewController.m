//
//  ViewController.m
//  XTYModelDemo
//
//  Created by Michael on 16/8/26.
//  Copyright © 2016年 Michael. All rights reserved.
//

#import "ViewController.h"
#import "XTYGitHubUserItem.h"
#import "XTYJson.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self parseJsonData];
}

- (XTYGitHubUserItem *)parseJsonData
{
    NSString *filePath = [[NSBundle mainBundle] pathForResource:@"gitHub_user" ofType:@"json"];
    XTYJson *git_user_json = [XTYJson jsonWithData:[NSData dataWithContentsOfFile:filePath]];
    XTYGitHubUserItem *userItem = [[XTYGitHubUserItem alloc] initWithJson:git_user_json];
    
    return userItem;
}

@end