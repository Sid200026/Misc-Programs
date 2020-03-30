const displayMessage = (message) => {
    return new Promise((resolve, reject) => {
      setTimeout(() => {
        /* if (message === 'Wassup?') {
          return reject('Something went wrong');
        } */
        return resolve(message);
      }, 3000);
    });
  }
  
  // promise
  
  /* displayMessage('Hello').then(result => {
    console.log('result', result);
    displayMessage('There?').then(result => {
      console.log('result', result);
      displayMessage('Wassup?').then(result => {
        console.log('result', result);
      }).catch(error => {
        console.log('Error', error);
      });
    }).catch(error => {
      console.log('Error', error);
    })
  }).catch(error => {
    console.log('Error', error);
  }); */
  
  const greetings = async () => {
    return 'Hey'
  }
  
  /* greetings().then(result => console.log('***', result)); */
  
  const myFunc = async () => {
    try {
      let result = '';
      result = await displayMessage('Hello');
      console.log(result);
      result = await displayMessage('There?');
      console.log(result);
      result = await displayMessage('Wassup?');
      console.log(result);
      result = await greetings();
      console.log(result);
    } catch (error) {
      console.log('Error', error);
    }
  }
  
  myFunc();