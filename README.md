# SecureThisHouse
Basic security protocol implementation using a lock and key model to 'secure' access to a house

#Policy

Only users with an authorized key can enter the house. To enter the house, the user must first:

    Insert their key in the lock
    Turn the key in the lock
    Enter the house

Note that testing if a key is valid is done only when the key is turned.

For turning the key and entering the house, it must be the same user that puts the key in the lock, turns the key, and enters the house.

A house can be rekeyed (this means that the old keys are no longer useable) with new keys only by the owner, and only if the owner is inside the house.

Firefighters can enter with the secret key (literal string) FIREFIGHTER_SECRET_KEY.

There is only one lock and one door. The lock will always be accessed in the following way:

    insert key
    turn the key
    enter the house

Other commands can be issued in between insert, turn, and enter.

For example, the following situations will never happen:

    insert, enter
    insert, turn, insert
    turn, enter
    insert, turn, turn, enter

#Interface

The executable should be started with the following CLI format:

./secure_house <owner_name> <key_1> <key_2> ... <key_n>

where <owner_name> is the name of the owner, and <key_1> through <key_n> are all authorized keys for the house.

#Commands

INSERT KEY <user_name> <key>

<user_name> inserts key key into the door. Response should be: KEY <key> INSERTED BY <user_name>

TURN KEY <user_name>

<user_name> turns the key in the door. Possible responses are: SUCCESS <user_name> TURNS KEY <key> or FAILURE <user_name> UNABLE TO TURN KEY <key>

ENTER HOUSE <user_name>

<user_name> enters the house. Possible responses are: ACCESS DENIED or ACCESS ALLOWED.

WHO'S INSIDE?

Who is currently inside the house? Response must be a comma-separated list of user names, ordered by access time (earlier access first): <user_name_1>, <user_name_2>, <user_name_3>... or NOBODY HOME if there are no users in the house.

CHANGE LOCKS <user_name> <key_1> <key_2> ... <key_n>

<user_name> wishes to rekey the house with new given keys <key_1>, <key_2>, ..., <key_n>. Possible responses are: ACCESS DENIED or OK

LEAVE HOUSE <user_name>

<user_name> leaves the house. Possible responses are: OK or <user_name> NOT HERE

If any events are received that are not according to this specification, the response will be: ERROR.
Example

Running the program as follows:

./secure_house selina foobar key2 key3

Given the input:

INSERT KEY adam key
TURN KEY adam
ENTER HOUSE adam
INSERT KEY pat foobar
TURN KEY pat
ENTER HOUSE pat
WHO'S INSIDE?

Will produce the following output:

KEY key INSERTED BY adam
FAILURE adam UNABLE TO TURN KEY key
ACCESS DENIED
KEY foobar INSERTED BY pat
SUCCESS pat TURNS KEY foobar
ACCESS ALLOWED
pat

