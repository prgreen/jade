local jade = require "core.event.jade"

-- jade knows "init" and "tick"
-- one "init" event is generated at the start of the program
-- one "tick" is generated every frame

-- additional events should be registered below:
jade.create_event("exit")
