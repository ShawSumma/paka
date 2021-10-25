module ext.paka.parse.map;

import purr.err;
import purr.srcloc;
import purr.ast.walk;
import purr.ast.ast;

Node ident(string name) {
	if (name[0] == '@') {
		return new Form("index", new Ident("this"), new Value(name[1..$]));
	} else {
		return cast(Node) new Ident(name);
	}
}