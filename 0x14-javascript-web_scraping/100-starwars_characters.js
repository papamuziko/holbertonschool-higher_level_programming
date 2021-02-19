#!/usr/bin/node
const request = require('request');

request('https://swapi-api.hbtn.io/api/films/' + process.argv[2] + '/?format=json', function (error, response, body) {
  if (error) {
    console.log(error);
  }
  const jCharacters = JSON.parse(body).characters;
  for (let index = 0; index < jCharacters.length; index++) {
    request(jCharacters[index] + '?format=json', function (cerror, cresponse, cbody) {
      if (cerror) {
        console.log(cerror);
      }
      const jCharacter = JSON.parse(cbody);
      console.log(jCharacter.name);
    });
  }
});
