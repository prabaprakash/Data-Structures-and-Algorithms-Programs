var logger = require('./Logger');

logger.log('Hello World');
logger.log('Hi World');
logger.log('Yo World');

logger.changeStrategy('none');

logger.log('Hello World');
logger.log('Hi World');
logger.log('Yo World');
