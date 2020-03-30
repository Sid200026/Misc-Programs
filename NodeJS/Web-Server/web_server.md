# Web Server using ExpressJS

### Whenever we run a nodeJS script we are given access to some mathods or properties by default like

- require : Used to include npm packages, node packages or our own files
- \_\_dirname : Gives the directory where the nodejs script is currently present from the machine root
- \_\_filename : Gives the path of the file from the machine root

## ExpressJS Basics

    app.METHOD(PATH, HANDLER)

Where:

app is an instance of express.
METHOD is an HTTP request method, in lowercase.
PATH is a path on the server.
HANDLER is the function executed when the route is matched.

## Serving Static Files

To serve static files such as images, CSS files, and JavaScript files, use the express.static built-in middleware function in Express.

    express.static(root, [options])

The root argument specifies the root directory from which to serve static assets.

Arguments for options : https://expressjs.com/en/4x/api.html#express.static

    var options = {
    dotfiles: 'ignore',
    etag: false,
    extensions: ['htm', 'html'],
    index: false,
    maxAge: '1d',
    redirect: false,
    setHeaders: function (res, path, stat) {
        res.set('x-timestamp', Date.now())
    }
    }

    app.use(express.static('public', options))

For example, use the following code to serve images, CSS files, and JavaScript files in a directory named public:

    app.use(express.static('public'))

Now, we can load the files that are in the public directory:

http://localhost:3000/images/kitten.jpg

http://localhost:3000/css/style.css

http://localhost:3000/js/app.js

http://localhost:3000/images/bg.png

http://localhost:3000/hello.html

To use multiple static assets directories, call the express.static middleware function multiple times:

    app.use(express.static('public'))
    app.use(express.static('files'))

To create a virtual path prefix (where the path does not actually exist in the file system) for files that are served by the express.static function, specify a mount path for the static directory, as shown below:

    app.use('/static', express.static('public'))

http://localhost:3000/static/images/kitten.jpg

http://localhost:3000/static/css/style.css

http://localhost:3000/static/js/app.js

http://localhost:3000/static/images/bg.png

http://localhost:3000/static/hello.html

However, the path that you provide to the express.static function is relative to the directory from where you launch your node process. If you run the express app from another directory, it’s safer to use the absolute path of the directory that you want to serve:

    app.use('/static', express.static(path.join(__dirname, 'public')))

When we serve html file at a path say "/web" then if we type localhost:3000/web then if there is a file named index.html in that directory then it is displayed. If we want to see other html file then we need to give the filepath as well. This is because index.html has a special meaning in Web Programming.

When we setup the routes, we need to think of the order in which we do as the first matching case will only be used.

Whenever we want to serve static file using Express, we need to pass the exact location of that file starting from the root directory. To do this we use \_\_dirname to get the current directory and then navigate to the static file path. _We can use relative imports. Better practice is the import to be aboslute._

To get the file path, we can do string manipulation for \_\_dirname however we can use a core node module to achieve this which is a better way.

There is a special routing method, app.all(), used to load middleware functions at a path for all HTTP request methods. For example, the following handler is executed for requests to the route “/secret” whether using GET, POST, PUT, DELETE, or any other HTTP request method supported in the http module.

    app.all('/secret', function (req, res, next) {
        console.log('Accessing the secret section ...')
        next() // pass control to the next handler
    })

We can even route based on regular expressions

    app.get(/.*fly$/, function (req, res) {
        res.send('/.*fly$/')
    })

##### Route Parameters

Route parameters are named URL segments that are used to capture the values specified at their position in the URL. The captured values are populated in the req.params object, with the name of the route parameter specified in the path as their respective keys.

Route path: /users/:userId/books/:bookId

Request URL: http://localhost:3000/users/34/books/8989

req.params: { "userId": "34", "bookId": "8989" }

    app.get('/users/:userId/books/:bookId', function (req, res) {
        res.send(req.params)
    })

Route path: /flights/:from-:to

Request URL: http://localhost:3000/flights/LAX-SFO

req.params: { "from": "LAX", "to": "SFO" }

---

Route path: /plantae/:genus.:species

Request URL: http://localhost:3000/plantae/Prunus.persica

req.params: { "genus": "Prunus", "species": "persica" }

---

To have more control over the exact string that can be matched by a route parameter, you can append a regular expression in parentheses (()):

Route path: /user/:userId(\d+)

Request URL: http://localhost:3000/user/42

req.params: {"userId": "42"}

Because the regular expression is usually part of a literal string, be sure to escape any \ characters with an additional backslash, for example \\d+.

You can provide multiple callback functions that behave like middleware to handle a request. The only exception is that these callbacks might invoke next('route') to bypass the remaining route callbacks. You can use this mechanism to impose pre-conditions on a route, then pass control to subsequent routes if there’s no reason to proceed with the current route.

Route handlers can be in the form of a function, an array of functions, or combinations of both, as shown in the following examples.

    app.get('/example/b', function (req, res, next) {
        console.log('the response will be sent by the next function ...')
        next()
    }, function (req, res) {
        res.send('Hello from B!')
    })

An array of callback functions can handle a route. For example:

    var cb0 = function (req, res, next) {
        console.log('CB0')
        next()
    }

    var cb1 = function (req, res, next) {
        console.log('CB1')
        next()
    }

    var cb2 = function (req, res) {
        res.send('Hello from C!')
    }

    app.get('/example/c', [cb0, cb1, cb2])

A combination of independent functions and arrays of functions can handle a route. For example:

    var cb0 = function (req, res, next) {
        console.log('CB0')
        next()
    }

    var cb1 = function (req, res, next) {
        console.log('CB1')
        next()
    }

    app.get('/example/d', [cb0, cb1], function (req, res, next) {
        console.log('the response will be sent by the next function ...')
        next()
    }, function (req, res) {
        res.send('Hello from D!')
    })

Method Description

res.download() Prompt a file to be downloaded.

res.end() End the response process.

res.json() Send a JSON response.

res.jsonp() Send a JSON response with JSONP support.

res.redirect() Redirect a request.

res.render() Render a view template.

res.send() Send a response of various types.

res.sendFile() Send a file as an octet stream.

res.sendStatus() Set the response status code and send its string representation as the response body.

### app.route()

You can create chainable route handlers for a route path by using app.route(). Because the path is specified at a single location, creating modular routes is helpful, as is reducing redundancy and typos. For more information about routes, see: Router() documentation.

Here is an example of chained route handlers that are defined by using app.route().

    app.route('/book')
    .get(function (req, res) {
        res.send('Get a random book')
    })
    .post(function (req, res) {
        res.send('Add a book')
    })
    .put(function (req, res) {
        res.send('Update the book')
    })

### express.Router

Use the express.Router class to create modular, mountable route handlers. A Router instance is a complete middleware and routing system; for this reason, it is often referred to as a “mini-app”.

The following example creates a router as a module, loads a middleware function in it, defines some routes, and mounts the router module on a path in the main app.

Create a router file named birds.js in the app directory, with the following content:

    var express = require('express')
    var router = express.Router()

    // middleware that is specific to this router
    router.use(function timeLog (req, res, next) {
        console.log('Time: ', Date.now())
    next()
    })
    // define the home page route
    router.get('/', function (req, res) {
        res.send('Birds home page')
    })
    // define the about route
    router.get('/about', function (req, res) {
        res.send('About birds')
    })

    module.exports = router

Then, load the router module in the app:

    var birds = require('./birds')

    // ...

    app.use('/birds', birds)

The app will now be able to handle requests to /birds and /birds/about, as well as call the timeLog middleware function that is specific to the route.

---

# API Reference

## Important Response methods

More at http://expressjs.com/en/4x/api.html#res

### res.download(path [, filename][, options] [, fn])

The optional options argument is supported by Express v4.16.0 onwards.

Transfers the file at path as an “attachment”. Typically, browsers will prompt the user for download. By default, the Content-Disposition header “filename=” parameter is path (this typically appears in the browser dialog). Override this default with the filename parameter.

When an error occurs or transfer is complete, the method calls the optional callback function fn. This method uses res.sendFile() to transfer the file.

The optional options argument passes through to the underlying res.sendFile() call, and takes the exact same parameters.

    res.download('/report-12345.pdf')

    res.download('/report-12345.pdf', 'report.pdf')

    res.download('/report-12345.pdf', 'report.pdf', function (err) {
    if (err) {
        // Handle error, but keep in mind the response may be partially-sent
        // so check res.headersSent
    } else {
        // decrement a download credit, etc.
    }
    })

### res.get(field)

Returns the HTTP response header specified by field. The match is case-insensitive.

    res.get('Content-Type')
    // => "text/plain"

### res.json([body])

Sends a JSON response. This method sends a response (with the correct content-type) that is the parameter converted to a JSON string using JSON.stringify().

The parameter can be any JSON type, including object, array, string, Boolean, number, or null, and you can also use it to convert other values to JSON.

    res.json(null)
    res.json({ user: 'tobi' })
    res.status(500).json({ error: 'message' })

### res.redirect([status,] path)

Redirects to the URL derived from the specified path, with specified status, a positive integer that corresponds to an HTTP status code . If not specified, status defaults to “302 “Found”.

    res.redirect('/foo/bar')
    res.redirect('http://example.com')
    res.redirect(301, 'http://example.com')
    res.redirect('../login')

Redirects can be a fully-qualified URL for redirecting to a different site:

    res.redirect('http://google.com')

Redirects can be relative to the root of the host name. For example, if the application is on http://example.com/admin/post/new, the following would redirect to the URL http://example.com/admin:

    res.redirect('/admin')

Redirects can be relative to the current URL. For example, from http://example.com/blog/admin/ (notice the trailing slash), the following would redirect to the URL http://example.com/blog/admin/post/new.

    res.redirect('post/new')

Redirecting to post/new from http://example.com/blog/admin (no trailing slash), will redirect to http://example.com/blog/post/new.

If you found the above behavior confusing, think of path segments as directories (with trailing slashes) and files, it will start to make sense.

Path-relative redirects are also possible. If you were on http://example.com/admin/post/new, the following would redirect to http://example.com/admin/post:

    res.redirect('..')

A back redirection redirects the request back to the referer, defaulting to / when the referer is missing.

res.redirect('back')

### res.sendStatus(statusCode)

Sets the response HTTP status code to statusCode and send its string representation as the response body.

    res.sendStatus(200) // equivalent to res.status(200).send('OK')
    res.sendStatus(403) // equivalent to res.status(403).send('Forbidden')
    res.sendStatus(404) // equivalent to res.status(404).send('Not Found')
    res.sendStatus(500) // equivalent to res.status(500).send('Internal Server Error')

### res.status(code)

Sets the HTTP status for the response. It is a chainable alias of Node’s response.statusCode.

    res.status(403).end()
    res.status(400).send('Bad Request')
    res.status(404).sendFile('/absolute/path/to/404.png')

### res.type(type)

Sets the Content-Type HTTP header to the MIME type as determined by mime.lookup() for the specified type. If type contains the “/” character, then it sets the Content-Type to type.

    res.type('.html')
    // => 'text/html'
    res.type('html')
    // => 'text/html'
    res.type('json')
    // => 'application/json'
    res.type('application/json')
    // => 'application/json'
    res.type('png')
    // => 'image/png'

### res.set(field [, value])

Sets the response’s HTTP header field to value. To set multiple fields at once, pass an object as the parameter.

    res.set('Content-Type', 'text/plain')

    res.set({
        'Content-Type': 'text/plain',
        'Content-Length': '123',
    ETag: '12345'

})

### res.sendFile(path [, options][, fn])

Transfers the file at the given path. Sets the Content-Type response HTTP header field based on the filename’s extension. Unless the root option is set in the options object, path must be an absolute path to the file.

    app.get('/file/:name', function (req, res, next) {
        var options = {
            root: path.join(__dirname, 'public'),
            dotfiles: 'deny',
            headers: {
            'x-timestamp': Date.now(),
            'x-sent': true
            }
        }

    var fileName = req.params.name
        res.sendFile(fileName, options, function (err) {
            if (err) {
            next(err)
            } else {
            console.log('Sent:', fileName)
            }
        })
    })

## Important Request Methods

More at http://expressjs.com/en/4x/api.html#req

The req object represents the HTTP request and has properties for the request query string, parameters, body, HTTP headers, and so on. In this documentation and by convention, the object is always referred to as req (and the HTTP response is res) but its actual name is determined by the parameters to the callback function in which you’re working.

### req.app

This property holds a reference to the instance of the Express application that is using the middleware.

If you follow the pattern in which you create a module that just exports a middleware function and require() it in your main file, then the middleware can access the Express instance via req.app

### req.baseUrl

The URL path on which a **router instance** was mounted.

The req.baseUrl property is similar to the mountpath property of the app object, except app.mountpath returns the matched path pattern(s).

    var greet = express.Router()

    greet.get('/jp', function (req, res) {
        console.log(req.baseUrl) // /greet
        res.send('Konichiwa!')
    })

    app.use('/greet', greet) // load the router on '/greet'

### req.hostname

Contains the hostname derived from the Host HTTP header.

    // Host: "example.com:3000"
    console.dir(req.hostname)
    // => 'example.com'

### req.ip

Contains the remote IP address of the request.

When the trust proxy setting does not evaluate to false, the value of this property is derived from the left-most entry in the X-Forwarded-For header. This header can be set by the client or by the proxy.

console.dir(req.ip)
// => '127.0.0.1'

### req.method

Contains a string corresponding to the HTTP method of the request: GET, POST, PUT, and so on.

### req.originalUrl ; req.baseUrl ; req.path

    app.use('/admin', function (req, res, next) { // GET 'http://www.example.com/admin/new'
        console.dir(req.originalUrl) // '/admin/new'
        console.dir(req.baseUrl) // '/admin'
        console.dir(req.path) // '/new'
        next()
    })

### req.params

This property is an object containing properties mapped to the named route “parameters”. For example, if you have the route /user/:name, then the “name” property is available as req.params.name. This object defaults to {}.

    // GET /user/tj
    console.dir(req.params.name)
    // => 'tj'

When you use a regular expression for the route definition, capture groups are provided in the array using req.params[n], where n is the nth capture group. This rule is applied to unnamed wild card matches with string routes such as /file/\*:

    // GET /file/javascripts/jquery.js
    console.dir(req.params[0])
    // => 'javascripts/jquery.js'

### req.protocol

Contains the request protocol string: either http or (for TLS requests) https.

When the trust proxy setting does not evaluate to false, this property will use the value of the X-Forwarded-Proto header field if present. This header can be set by the client or by the proxy.

    console.dir(req.protocol)
    // => 'http'

### req.query

This property is an object containing a property for each query string parameter in the route. If there is no query string, it is the empty object, {}.

As req.query’s shape is based on user-controlled input, all properties and values in this object are untrusted and should be validated before trusting. For example, req.query.foo.toString() may fail in multiple ways, for example foo may not be there or may not be a string, and toString may not be a function and instead a string or other user-input.

    // GET /search?q=tobi+ferret
    console.dir(req.query.q)
    // => 'tobi ferret'

    // GET /shoes?order=desc&shoe[color]=blue&shoe[type]=converse
    console.dir(req.query.order)
    // => 'desc'

    console.dir(req.query.shoe.color)
    // => 'blue'

    console.dir(req.query.shoe.type)
    // => 'converse'

    // GET /shoes?color[]=blue&color[]=black&color[]=red
    console.dir(req.query.color)
    // => ['blue', 'black', 'red']

### req.secure

A Boolean property that is true if a TLS connection is established. Equivalent to:

console.dir(req.protocol === 'https')
// => true

### req.get(field)

Returns the specified HTTP request header field (case-insensitive match). The Referrer and Referer fields are interchangeable.

    req.get('Content-Type')
    // => "text/plain"

    req.get('content-type')
    // => "text/plain"

    req.get('Something')
    // => undefined

## App methods

More at http://expressjs.com/en/4x/api.html#app

The app object conventionally denotes the Express application. Create it by calling the top-level express() function exported by the Express module:

The app object has methods for

1. Routing HTTP requests; see for example, app.METHOD and app.param.
2. Configuring middleware; see app.route.
3. Rendering HTML views; see app.render.
4. Registering a template engine; see app.engine.
   It also has settings (properties) that affect how the application behaves; for more information, see Application settings.

## app.locals

The app.locals object has properties that are local variables within the application.

    console.dir(app.locals.title)
    // => 'My App'

    console.dir(app.locals.email)
    // => 'me@myapp.com'

Once set, the value of app.locals properties persist throughout the life of the application, in contrast with res.locals properties that are valid only for the lifetime of the request.

You can access local variables in templates rendered within the application. This is useful for providing helper functions to templates, as well as application-level data. Local variables are available in middleware via req.app.locals (see req.app)

    app.locals.title = 'My App'
    app.locals.strftime = require('strftime')
    app.locals.email = 'me@myapp.com'

## app.all(path, callback [, callback ...])

This method is like the standard app.METHOD() methods, except it matches all HTTP verbs.

The following callback is executed for requests to /secret whether using GET, POST, PUT, DELETE, or any other HTTP request method:

    app.all('/secret', function (req, res, next) {
        console.log('Accessing the secret section ...')
        next() // pass control to the next handler
    })

The app.all() method is useful for mapping “global” logic for specific path prefixes or arbitrary matches. For example, if you put the following at the top of all other route definitions, it requires that all routes from that point on require authentication, and automatically load a user. Keep in mind that these callbacks do not have to act as end-points: loadUser can perform a task, then call next() to continue matching subsequent routes.

    app.all('*', requireAuthentication, loadUser)

Or the equivalent:

    app.all('*', requireAuthentication)
    app.all('*', loadUser)

Another example is white-listed “global” functionality. The example is similar to the ones above, but it only restricts paths that start with “/api”:

    app.all('/api/*', requireAuthentication)

## app.delete(path, callback [, callback ...])

Routes HTTP DELETE requests to the specified path with the specified callback functions. For more information, see the routing guide.

#### callback Callback functions; can be:

A middleware function.

A series of middleware functions (separated by commas).

An array of middleware functions.

A combination of all of the above.

    app.delete('/', function (req, res) {
        res.send('DELETE request to homepage')
    })

## app.listen(path, [callback])

Starts a UNIX socket and listens for connections on the given path. This method is identical to Node’s http.Server.listen().

    var express = require('express')
    var app = express()
    app.listen('/tmp/sock')

## app.listen([port[, host[, backlog]]][, callback])

Binds and listens for connections on the specified host and port. This method is identical to Node’s http.Server.listen().

If port is omitted or is 0, the operating system will assign an arbitrary unused port, which is useful for cases like automated tasks (tests, etc.).

    var express = require('express')
    var app = express()
    app.listen(3000)

The app returned by express() is in fact a JavaScript Function, designed to be passed to Node’s HTTP servers as a callback to handle requests. This makes it easy to provide both HTTP and HTTPS versions of your app with the same code base, as the app does not inherit from these (it is simply a callback):

    var express = require('express')
    var https = require('https')
    var http = require('http')
    var app = express()

    http.createServer(app).listen(80)
    https.createServer(options, app).listen(443)

## app.param([name], callback)

Add callback triggers to route parameters, where name is the name of the parameter or an array of them, and callback is the callback function. The parameters of the callback function are the request object, the response object, the next middleware, the value of the parameter and the name of the parameter, in that order.

If name is an array, the callback trigger is registered for each parameter declared in it, in the order in which they are declared. Furthermore, for each declared parameter except the last one, a call to next inside the callback will call the callback for the next declared parameter. For the last parameter, a call to next will call the next middleware in place for the route currently being processed, just like it would if name were just a string.

    app.param('user', function (req, res, next, id) {
    // try to get the user details from the User model and attach it to the request object
        User.find(id, function (err, user) {
            if (err) {
            next(err)
            } else if (user) {
            req.user = user
            next()
            } else {
            next(new Error('failed to load user'))
            }
        })
    })

Param callback functions are local to the router on which they are defined. They are not inherited by mounted apps or routers. Hence, param callbacks defined on app will be triggered only by route parameters defined on app routes.

All param callbacks will be called before any handler of any route in which the param occurs, and they will each be called only once in a request-response cycle, even if the parameter is matched in multiple routes, as shown in the following examples.

    app.param('id', function (req, res, next, id) {
        console.log('CALLED ONLY ONCE')
        next()
    })

    app.get('/user/:id', function (req, res, next) {
        console.log('although this matches')
        next()
    })

    app.get('/user/:id', function (req, res) {
        console.log('and this matches too')
        res.end()
    })

## app.use([path,] callback [, callback...])

Mounts the specified middleware function or functions at the specified path: the middleware function is executed when the base of the requested path matches path.

    app.use(function (req, res, next) {
        console.log('Time: %d', Date.now())
        next()
    })

    // this middleware will not allow the request to go beyond it
    app.use(function (req, res, next) {
        res.send('Hello World')
    })

    // requests will never reach this route
    app.get('/', function (req, res) {
        res.send('Welcome')
    })

#### Error-handling middleware

Error-handling middleware always takes four arguments. You must provide four arguments to identify it as an error-handling middleware function. Even if you don’t need to use the next object, you must specify it to maintain the signature. Otherwise, the next object will be interpreted as regular middleware and will fail to handle errors. For details about error-handling middleware, see: Error handling.

Define error-handling middleware functions in the same way as other middleware functions, except with four arguments instead of three, specifically with the signature **(err, req, res, next))**:

    app.use(function (err, req, res, next) {
        console.error(err.stack)
        res.status(500).send('Something broke!')
    })

router is valid middleware.

    var router = express.Router();
    router.get('/', function (req, res, next) {
        next();
    });
    app.use(router);

An Express app is valid middleware.

    var subApp = express();
    subApp.get('/', function (req, res, next) {
        next();
    });
    app.use(subApp);

## Express Methods

More at http://expressjs.com/en/4x/api.html#express

## express.json([options])

This is a built-in middleware function in Express. It parses incoming requests with JSON payloads and is based on body-parser.

Returns middleware that only parses JSON and only looks at requests where the Content-Type header matches the type option. This parser accepts any Unicode encoding of the body and supports automatic inflation of gzip and deflate encodings.

A new body object containing the parsed data is populated on the request object after the middleware (i.e. req.body), or an empty object ({}) if there was no body to parse, the Content-Type was not matched, or an error occurred.

As req.body’s shape is based on user-controlled input, all properties and values in this object are untrusted and should be validated before trusting. For example, req.body.foo.toString() may fail in multiple ways, for example foo may not be there or may not be a string, and toString may not be a function and instead a string or other user-input.

## express.Router([options])

Creates a new router object.

var router = express.Router([options])

## express.static(root, [options])

This is a built-in middleware function in Express. It serves static files and is based on serve-static.

The root argument specifies the root directory from which to serve static assets. The function determines the file to serve by combining req.url with the provided root directory. When a file is not found, instead of sending a 404 response, it instead calls next() to move on to the next middleware, allowing for stacking and fall-backs.

    var options = {
        dotfiles: 'ignore',
        etag: false,
        extensions: ['htm', 'html'],
        index: false,
        maxAge: '1d',
        redirect: false,
        setHeaders: function (res, path, stat) {
            res.set('x-timestamp', Date.now())
        }
    }

    app.use(express.static('public', options))

## express.text([options])

This middleware is available in Express v4.17.0 onwards.

This is a built-in middleware function in Express. It parses incoming request payloads into a string and is based on body-parser.

Returns middleware that parses all bodies as a string and only looks at requests where the Content-Type header matches the type option. This parser accepts any Unicode encoding of the body and supports automatic inflation of gzip and deflate encodings.

A new body string containing the parsed data is populated on the request object after the middleware (i.e. req.body), or an empty object ({}) if there was no body to parse, the Content-Type was not matched, or an error occurred.

## Router

More at http://expressjs.com/en/4x/api.html#router

A router object is an isolated instance of middleware and routes. You can think of it as a “mini-application,” capable only of performing middleware and routing functions. Every Express application has a built-in app router.

A router behaves like middleware itself, so you can use it as an argument to app.use() or as the argument to another router’s use() method.

The top-level express object has a Router() method that creates a new router object.

Once you’ve created a router object, you can add middleware and HTTP method routes (such as get, put, post, and so on) to it just like an application. For example:

### router.all(path, [callback, ...] callback)

This method is just like the router.METHOD() methods, except that it matches all HTTP methods (verbs).

This method is extremely useful for mapping “global” logic for specific path prefixes or arbitrary matches. For example, if you placed the following route at the top of all other route definitions, it would require that all routes from that point on would require authentication, and automatically load a user. Keep in mind that these callbacks do not have to act as end points; loadUser can perform a task, then call next() to continue matching subsequent routes.

    router.all('*', requireAuthentication, loadUser)

Or the equivalent:

    router.all('*', requireAuthentication)
    router.all('*', loadUser)

Another example of this is white-listed “global” functionality. Here the example is much like before, but it only restricts paths prefixed with “/api”:

    router.all('/api/*', requireAuthentication)

### router.METHOD(path, [callback, ...] callback)

The router.METHOD() methods provide the routing functionality in Express, where METHOD is one of the HTTP methods, such as GET, PUT, POST, and so on, in lowercase. Thus, the actual methods are router.get(), router.post(), router.put(), and so on.

    router.get(/^\/commits\/(\w+)(?:\.\.(\w+))?$/, function (req, res) {
        var from = req.params[0]
        var to = req.params[1] || 'HEAD'
        res.send('commit range ' + from + '..' + to)
    })

### router.param(name, callback)

Adds callback triggers to route parameters, where name is the name of the parameter and callback is the callback function. Although name is technically optional, using this method without it is deprecated starting with Express v4.11.0 (see below).

The parameters of the callback function are:

1. req, the request object.
2. res, the response object.
3. next, indicating the next middleware function.
4. The value of the name parameter.
5. The name of the parameter.

   router.param('user', function (req, res, next, id) {
   // try to get the user details from the User model and attach it to the request object
   User.find(id, function (err, user) {
   if (err) {
   next(err)
   } else if (user) {
   req.user = user
   next()
   } else {
   next(new Error('failed to load user'))
   }
   })
   })

### router.route(path)

Returns an instance of a single route which you can then use to handle HTTP verbs with optional middleware. Use router.route() to avoid duplicate route naming and thus typing errors.

    var router = express.Router()

    router.param('user_id', function (req, res, next, id) {
    // sample user, would actually fetch from DB, etc...
        req.user = {
            id: id,
            name: 'TJ'
        }
    next()
    })

    router.route('/users/:user_id')
    .all(function (req, res, next) {
        // runs for all HTTP verbs first
        // think of it as route specific middleware!
        next()
    })
    .get(function (req, res, next) {
        res.json(req.user)
    })
    .put(function (req, res, next) {
        // just an example of maybe updating the user
        req.user.name = req.params.name
        // save user ... etc
        res.json(req.user)
    })
    .post(function (req, res, next) {
        next(new Error('not implemented'))
    })
    .delete(function (req, res, next) {
        next(new Error('not implemented'))
    })

## router.use([path], [function, ...] function)

Uses the specified middleware function or functions, with optional mount path path, that defaults to “/”.

This method is similar to app.use(). A simple example and use case is described below. See app.use() for more information.

Middleware is like a plumbing pipe: requests start at the first middleware function defined and work their way “down” the middleware stack processing for each path they match.

---

# Middlewares

## Application-level middleware

Bind application-level middleware to an instance of the app object by using the app.use() and app.METHOD() functions, where METHOD is the HTTP method of the request that the middleware function handles (such as GET, PUT, or POST) in lowercase.

## Router-level middleware

Router-level middleware works in the same way as application-level middleware, except it is bound to an instance of express.Router().

## Error-handling middleware

Error-handling middleware always takes four arguments. You must provide four arguments to identify it as an error-handling middleware function. Even if you don’t need to use the next object, you must specify it to maintain the signature. Otherwise, the next object will be interpreted as regular middleware and will fail to handle errors.

Define error-handling middleware functions in the same way as other middleware functions, except with four arguments instead of three, specifically with the signature (err, req, res, next)):

## Third-party middleware

Use third-party middleware to add functionality to Express apps.

Install the Node.js module for the required functionality, then load it in your app at the application level or at the router level.

The following example illustrates installing and loading the cookie-parsing middleware function cookie-parser.

    var express = require('express')
    var app = express()
    var cookieParser = require('cookie-parser')

    // load the cookie-parsing middleware
    app.use(cookieParser())

## Template Engines

A template engine enables you to use static template files in your application. At runtime, the template engine replaces variables in a template file with actual values, and transforms the template into an HTML file sent to the client. This approach makes it easier to design an HTML page.

    app.set('view engine', 'pug') // If we use pug as template engine

## Error Handling

Error Handling refers to how Express catches and processes errors that occur both synchronously and asynchronously. Express comes with a default error handler so you don’t need to write your own to get started.

### Catching Errors

It’s important to ensure that Express catches all errors that occur while running route handlers and middleware.

Errors that occur in synchronous code inside route handlers and middleware require no extra work. If synchronous code throws an error, then Express will catch and process it. For example:

    app.get('/', function (req, res) {
        throw new Error('BROKEN') // Express will catch this on its own.
    })

For errors returned from asynchronous functions invoked by route handlers and middleware, you must pass them to the next() function, where Express will catch and process them. For example:

    app.get('/', function (req, res, next) {
        fs.readFile('/file-does-not-exist', function (err, data) {
            if (err) {
            next(err) // Pass errors to Express.
            } else {
            res.send(data)
            }
        })
    })

If you pass anything to the next() function (except the string 'route'), Express regards the current request as being an error and will skip any remaining non-error handling routing and middleware functions.

    app.get('/', [
        function (req, res, next) {
            fs.writeFile('/inaccessible-path', 'data', next)
        },
        function (req, res) {
            res.send('OK')
        }
    ])

In the above example next is provided as the callback for fs.writeFile, which is called with or without errors. If there is no error the second handler is executed, otherwise Express catches and processes the error.

### The default error handler

Express comes with a built-in error handler that takes care of any errors that might be encountered in the app. This default error-handling middleware function is added at the end of the middleware function stack.

If you pass an error to next() and you do not handle it in a custom error handler, it will be handled by the built-in error handler; the error will be written to the client with the stack trace. The stack trace is not included in the production environment.

**Set the environment variable NODE_ENV to production, to run the app in production mode.**

So when you add a custom error handler, you must delegate to the default Express error handler, when the headers have already been sent to the client:

    function errorHandler (err, req, res, next) {
        if (res.headersSent) {
            return next(err)
        }
        res.status(500)
        res.render('error', { error: err })
    }


**You define error-handling middleware last, after other app.use() and routes calls; for example:**

    var bodyParser = require('body-parser')
    var methodOverride = require('method-override')

    app.use(bodyParser.urlencoded({
    extended: true
    }))
    app.use(bodyParser.json())
    app.use(methodOverride())
    app.use(logErrors)
    app.use(clientErrorHandler)
    app.use(errorHandler)