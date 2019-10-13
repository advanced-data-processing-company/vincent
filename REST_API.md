# API Design

## Reference

1. [MicroSoft API Design Guide](https://docs.microsoft.com/en-us/azure/architecture/best-practices/api-design)
2. [Google API Design Guide](https://cloud.google.com/apis/design/)
3. [Others](http://apistylebook.com/design/guidelines/google-api-design-guide#api-design)

## Log

|                     path                     | Create | Update | Rtrive | Delete |
| :------------------------------------------: | :----: | :----: | :----: | :----: |
| ROOT/Log/module_name?key1=value1&key2=value2 |   Yes  |  No    |   Yes  |   Yes  |

## Order
# an order is related to a specified client and is identified by client and the timestamp

|                     path                          | Create | Update | Rtrive | Delete |
| :----------------------------------------------:  | :----: | :----: | :----: | :----: |
| ROOT/Order/order_id?key1=client_id&key2=timestamp |   Yes  |   No   |   Yes  |   Yes  |
