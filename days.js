(() => {
  const start = new Date("2021-07-07").valueOf();

  const todayDate = new Date();
  todayDate.setHours(Math.abs(todayDate.getTimezoneOffset()) / 60);
  todayDate.setMinutes(0);
  todayDate.setSeconds(0);
  todayDate.setMilliseconds(0);

  console.log(
    `Today you should have done 'day${
      (todayDate.valueOf() - start) / (1000 * 60 * 60 * 24)
    }'`
  );
})();
