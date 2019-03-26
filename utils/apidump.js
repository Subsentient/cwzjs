
function ToCType(Item)
{
	if (Item instanceof Array)
	{
		var Str = '(array of ' + Item.length + ' elements, types ';

		for (Index in Item)
		{
			Str += typeof(Item[Index]) + ',';
		}
		return Str;
	}
	var Type = typeof Item;

	switch (Type)
	{
		case 'number':
			return 'int';
		case 'string':
			return 'const char*';
		case 'boolean':
			return 'bool';
		case 'object':
			return 'object';
		default:
			return null;
			break;
	}

	//Object, I guess
	
}

function eventStartLevel()
{
	for (Item in this)
	{
		//Numeric constants.
		if (Item === Item.toUpperCase() && typeof(this[Item]) === 'number')
		{
			debug('#define ' + Item + ' ' + this[Item]);
		}
	}

	var DroidList = enumDroid(me, DROID_ANY)

	var Droid = DroidList[0]

	debug('struct CWZJS_DROID\n{\n');
	for (Item in Droid)
	{
		debug('    ' + ToCType(Droid[Item]) + ' ' + Item + ';');
	}
	debug('}\n');

	var StructList = enumStruct(me, HQ);
	var Struct = StructList[0];
	
	debug('struct CWZJS_STRUCTURE\n{\n');
	for (Item in Struct)
	{
		debug('    ' + ToCType(Struct[Item]) + ' ' + Item + ';');
	}
	debug('}\n');
}
