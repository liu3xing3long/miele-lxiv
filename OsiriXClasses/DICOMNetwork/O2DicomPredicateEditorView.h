/*=========================================================================
 Program:   OsiriX
 
 Copyright (c) OsiriX Team
 All rights reserved.
 Distributed under GNU - LGPL
 
 See http://www.osirix-viewer.com/copyright.html for details.
 
 This software is distributed WITHOUT ANY WARRANTY; without even
 the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 PURPOSE.
 =========================================================================*/

#import <Cocoa/Cocoa.h>

@class DCMAttributeTag;
@class O2DicomPredicateEditorPopUpButton;
@class O2DicomPredicateEditorDatePicker;
@class O2DicomPredicateEditor;

@interface O2DicomPredicateEditorView : NSView <NSMenuDelegate, NSTextFieldDelegate> {
    BOOL _reviewing;
    NSInteger _tagsSortKey;
    NSMutableArray* _menuItems;
    // values
    DCMAttributeTag* _tag;
    NSInteger _operator;
    NSString* _stringValue;
    NSNumber* _numberValue;
    NSDate* _dateValue;
    NSInteger _within, _codeStringTag;
    // views
    O2DicomPredicateEditorPopUpButton* _tagsPopUp;
    O2DicomPredicateEditorPopUpButton* _operatorsPopUp;
    NSTextField* _stringValueTextField;
    NSTextField* _numberValueTextField;
    O2DicomPredicateEditorDatePicker* _datePicker;
    O2DicomPredicateEditorDatePicker* _timePicker;
    O2DicomPredicateEditorDatePicker* _dateTimePicker;
    O2DicomPredicateEditorPopUpButton* _withinPopUp;
    O2DicomPredicateEditorPopUpButton* _codeStringPopUp;
    NSTextField* _isLabel;
}

@property(retain,nonatomic, readonly) NSArray* tags;
@property NSInteger tagsSortKey;

@property(retain) DCMAttributeTag* tag;
@property NSInteger operat;
@property(retain,nonatomic) NSString* stringValue;
@property(retain) NSNumber* numberValue;
@property(retain) NSDate* dateValue;
@property NSInteger within, codeStringTag;

@property(assign) NSPredicate* predicate;

- (O2DicomPredicateEditor*)editor;

- (double)matchForPredicate:(NSPredicate*)predicate;

@end
