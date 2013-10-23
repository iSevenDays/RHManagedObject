//
//  RHManagedObject.h
//  Version: 0.9
//
//  Copyright (C) 2013 by Christopher Meyer
//  http://schwiiz.org/
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

typedef enum {
    RHAggregateMax,
	RHAggregateMin,
	RHAggregateAverage,
	RHAggregateSum
} RHAggregate;

#import <CoreData/CoreData.h>
@class RHManagedObjectContextManager;

@interface RHManagedObject : NSManagedObject

/* Abstract Classes */
+(NSString *)entityName;
+(NSString *)modelName;

+(NSEntityDescription *)entityDescription __deprecated;
+(NSEntityDescription *)entityDescriptionWithError:(NSError **)error;

+(NSError *)deleteStore;
+(NSError *)commit;

+(id)newEntity;
+(id)newEntityWithError:(NSError **)error;

+(id)newOrExistingEntityWithPredicate:(NSPredicate *)predicate __deprecated;
+(id)newOrExistingEntityWithPredicate:(NSPredicate *)predicate
                                error:(NSError **)error;

+(id)getWithPredicate:(NSPredicate *)predicate __deprecated;
+(id)getWithPredicate:(NSPredicate *)predicate
                error:(NSError **)error;

+(id)getWithPredicate:(NSPredicate *)predicate
	   sortDescriptor:(NSSortDescriptor *)descriptor __deprecated;
+(id)getWithPredicate:(NSPredicate *)predicate
       sortDescriptor:(NSSortDescriptor *)descriptor
                error:(NSError **)error;

+(NSArray *)fetchAll __deprecated;
+(NSArray *)fetchAllWithError:(NSError **)error;

+(NSArray *)fetchWithPredicate:(NSPredicate *)predicate __deprecated;

+(NSArray *)fetchWithPredicate:(NSPredicate *)predicate
                         error:(NSError **)error;

+(NSArray *)fetchWithPredicate:(NSPredicate *)predicate
				sortDescriptor:(NSSortDescriptor *)descriptor __deprecated;

+(NSArray *)fetchWithPredicate:(NSPredicate *)predicate
				sortDescriptor:(NSSortDescriptor *)descriptor
                         error:(NSError **)error;

+(NSArray *)fetchWithPredicate:(NSPredicate *)predicate
                sortDescriptor:(NSSortDescriptor *)descriptor
                     withLimit:(NSUInteger)limit __deprecated;

+(NSArray *)fetchWithPredicate:(NSPredicate *)predicate
                sortDescriptor:(NSSortDescriptor *)descriptor
                     withLimit:(NSUInteger)limit
                         error:(NSError **)error;

+(NSUInteger)count __deprecated;
+(NSUInteger)countWithError:(NSError **)error;

+(NSUInteger)countWithPredicate:(NSPredicate *)predicate __deprecated;
+(NSUInteger)countWithPredicate:(NSPredicate *)predicate error:(NSError **)error;

+(NSArray *)distinctValuesWithAttribute:(NSString *)attribute
							  predicate:(NSPredicate *)predicate __deprecated;

+(NSArray *)distinctValuesWithAttribute:(NSString *)attribute
                              predicate:(NSPredicate *)predicate
                                  error:(NSError **)error;

+(NSAttributeType)attributeTypeWithKey:(NSString *)key __deprecated;
+(NSAttributeType)attributeTypeWithKey:(NSString *)key
								 error:(NSError **)error;

+(id)aggregateWithType:(RHAggregate)aggregate
				   key:(NSString *)key
			 predicate:(NSPredicate *)predicate
		  defaultValue:(id)defaultValue __deprecated;

+(id)aggregateWithType:(RHAggregate)aggregate
                   key:(NSString *)key
             predicate:(NSPredicate *)predicate
          defaultValue:(id)defaultValue
                 error:(NSError **)error;

+(NSUInteger)deleteAll __deprecated;
+(NSUInteger)deleteAllWithError:(NSError **)error;

+(NSUInteger)deleteWithPredicate:(NSPredicate *)predicate __deprecated;
+(NSUInteger)deleteWithPredicate:(NSPredicate *)predicate error:(NSError **)error;

+(NSManagedObjectContext *)managedObjectContext __deprecated;
+(NSManagedObjectContext *)managedObjectContextForCurrentThread __deprecated;

+(NSManagedObjectContext *)managedObjectContextForCurrentThreadWithError:(NSError **)error;

+(RHManagedObjectContextManager *)managedObjectContextManager;

+(BOOL)doesRequireMigration __deprecated;
+(BOOL)doesRequireMigrationWithError:(NSError **)error;

/* Instance methods */
-(void)delete;
-(id)clone;
-(id)objectInCurrentThreadContext;
-(NSDictionary *)serialize;

@end

@interface ImageToDataTransformer : NSValueTransformer

@end