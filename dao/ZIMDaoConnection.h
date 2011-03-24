/*
 * Copyright 2011 Ziminji
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <sqlite3.h> // Requires libsqlite3.dylib

/*!
 @class				ZIMDaoConnection
 @discussion		This class represents an SQL statements.
 @updated			2011-03-23
 */
@interface ZIMDaoConnection : NSObject {
	
@private
	NSString *_dataSource;
	sqlite3 *_database;
	BOOL _isConnected;
	
}
/*!
 @method			initWithDataSource:
 @discussion		This constructor creates an instance of this class with the specified data source.
 @param dataSource	The file name to the database.
 @updated			2011-03-23
 */
- (id) initWithDataSource: (NSString *)dataSource;
/*!
 @method			open
 @discussion		This method will open a connection to the database.
 @updated			2011-03-23
 */
- (void) open;
/*!
 @method			execute:
 @discussion		This method will execute the specified SQL statement.
 @param sql			The SQL statement to be executed.
 @return			Either the last insert row id or TRUE.
 @updated			2011-03-23
 */
- (NSNumber *) execute: (NSString *)sql;
/*!
 @method			distinct:
 @discussion		This method will query with the specified SQL statement.
 @param sql			The SQL statement to be executed.
 @return			The result set.
 @updated			2011-03-23
 */
- (NSArray *) query: (NSString *)sql;
/*!
 @method			isConnected
 @discussion		This method checks whether a database connection currently exists.
 @return			Indicates whether a database connection exists.
 @updated			2011-03-23
 */
- (BOOL) isConnected;
/*!
 @method			close
 @discussion		This method will close an open database connection.
 @updated			2011-03-23
 */
- (void) close;

@end
