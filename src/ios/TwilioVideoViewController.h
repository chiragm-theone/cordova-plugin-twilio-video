@import TwilioVideo;
@import UIKit;
#import "TwilioVideoManager.h"
#import "TwilioVideoConfig.h"
#import "TwilioVideoPermissions.h"
#import "TwilioVideoUtils.h"
#import <WebKit/WebKit.h>
#import "TwilioMessageUtils.h"

@interface TwilioVideoViewController: UIViewController <TVIRemoteParticipantDelegate, TVIRoomDelegate, TVIVideoViewDelegate, TVICameraSourceDelegate, TwilioVideoActionProducerDelegate,UIImagePickerControllerDelegate, UINavigationControllerDelegate, WKNavigationDelegate>

// Configure access token manually for testing in `ViewDidLoad`, if desired! Create one manually in the console.
@property (nonatomic, strong) NSString *roomName;
@property (nonatomic, strong) NSString *accessToken;
@property (nonatomic, strong) TwilioVideoConfig *config;
@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSString *productURL;


#pragma mark Video SDK components

@property (nonatomic, strong) TVICameraSource *camera;
@property (nonatomic, strong) TVILocalVideoTrack *localVideoTrack;
@property (nonatomic, strong) TVILocalAudioTrack *localAudioTrack;
@property (nonatomic, strong) TVIRemoteParticipant *remoteParticipant;
@property (nonatomic, weak) TVIVideoView *remoteView;
@property (nonatomic, strong) TVIRoom *room;

#pragma mark UI Element Outlets and handles

// `TVIVideoView` created from a storyboard
@property (weak, nonatomic) IBOutlet TVIVideoView *previewView;

@property (nonatomic, weak) IBOutlet UIButton *disconnectButton;
@property (nonatomic, weak) IBOutlet UIButton *micButton;
@property (nonatomic, weak) IBOutlet UILabel *roomLabel;
@property (nonatomic, weak) IBOutlet UILabel *roomLine;
@property (nonatomic, weak) IBOutlet UIButton *cameraSwitchButton;
@property (nonatomic, weak) IBOutlet UIButton *videoButton;
@property (nonatomic, weak) IBOutlet UIButton *attachmentButton;
@property (nonatomic, weak) IBOutlet UIButton *chatButton;

@property(strong,nonatomic) WKWebView *webView;
@property (strong, nonatomic) NSString *chatURL;

@property (strong, nonatomic) UIAlertController *alertCtrl;
@property (strong, nonatomic) UIImagePickerController *imagePicker;

@property (strong, nonatomic) IBOutlet UIView *navigationView;

@property (strong, nonatomic) TwilioMessageUtils *twilioMessageUtils;

- (void)connectToRoom:(NSString*)room token: (NSString *)token;

@end
