
/* 
 * bailing, 2012/02/22
 * mainly from: Javascript: The Definitive Guide 5/e, section 17.6
 */

function run_onload(f) {
    if(run_onload.loaded) f();      // if already loaded, just invoke f() now
    else run_onload.funcs.push(f);  // otherwise, store it for later
}

/* array of functions to call when document loaded */
run_onload.funcs = [];
/* the functions have not been run yet */
run_onload.loaded = false;

run_onload.run = function() {
    /* if we've already run, do nothing */
    if(run_onload.loaded) return ;  

    for(var i = 0; i < run_onload.funcs.length; i++) {
        try { run_onload.funcs[i](); }
        catch(e) { /* skip the exception, shouldn't stop the rest */ }
    }

    run_onload.loaded = true;
    delete run_onload.funcs;    /* delete register functions */
    delete run_onload.run;      /* delete this function too! */
}

/* register run_onload.run() as the onload event handler for the window */
if(window.addEventListener) {
    window.addEventListener("load", run_onload.run, false);
} else if(window.attachEvent) {
    window.attachEvent("onload", run_onload.run);
} else {
    window.onload = run_onload.run;
}
