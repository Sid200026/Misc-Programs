module.exports = {
    defaultServerResponse: {
        status: 400,
        message: '',
        body: {}
    },
    productMessage: {
        PRODUCT_CREATED: 'Product created successfully',
        PRODUCT_FETCHED: 'Product fetched successfully',
        PRODUCT_UPDATED: 'Product updated successfully',
        PRODUCT_DELETED: 'Product deleted successfully',
        PRODUCT_NOT_FOUND: 'Product not found'
    },
    userMessage: {
        SIGNUP_SUCCESS: 'Signed up successfully',
        LOGIN_SUCCESS: 'Logged in successfully',
        USER_NOT_FOUND: 'User not found',
        DUPLICATE_EMAIL: 'User with this email already exists',
        INVALID_PASSWORD: 'Incorrect Password'
    },
    requestValidationMessage: {
        BAD_REQUEST: 'Invalid fields',
        TOKEN_MISSING: 'Token is missing from header'
    },
    databaseMessage: {
        INVALID_ID: 'Invalid ID'
    }
}