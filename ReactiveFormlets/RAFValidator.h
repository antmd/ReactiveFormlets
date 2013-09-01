//
//  RAFValidator.h
//  ReactiveFormlets
//
//  Created by Jon Sterling on 6/1/13.
//  Copyright (c) 2013 Jon Sterling. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReactiveCocoa/ReactiveCocoa.h>
#import "RAFMonoid.h"

@class RAFValidation, RACSignal;

// RAFValidator models a function that analyzes a function and returns
// a signal of RAFValidations. This is more powerful than a typical validator,
// which gives a single validation for every value tested; the streaming behavior
// is helpful if the validation of a particular value depends on some other state
// which may be changing over time (such as, say, if a value is only valid when
// the user is holding his/her phone in a certain direction).
//
// | RAFValidator (A : Type) : Type
// | RAFValidator A <: RACCommand (RAFValidation A)
@interface RAFValidator : RACCommand <RAFMonoid>
// | (builder : A → RACSignal (RAFValidation A)) → instancetype A
+ (instancetype)builder:(RACSignal *(^)(id object))builder;

// | (predicate : A → Bool, error : A → NSError) → instancetype A
+ (instancetype)predicate:(BOOL(^)(id object))predicate error:(NSError *(^)(id object))error;
@end
