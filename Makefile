generate_coverage_html:
	# Capturing initial coverage data: 
	lcov --capture --initial --directory . --output-file initial.info

	# Capturing execution coverage data: 
	lcov --capture --directory . --output-file coverage.info

	# Combining and generating report: 
	lcov --add-tracefile initial.info --add-tracefile coverage.info --output-file total.info

	# Generating HTML report:
	genhtml total.info --output-directory coverage_report