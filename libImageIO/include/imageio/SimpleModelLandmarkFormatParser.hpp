/*
 * SimpleModelLandmarkFormatParser.hpp
 *
 *  Created on: 29.05.2014
 *      Author: Patrik Huber
 */

#ifndef SIMPLEMODELLANDMARKFORMATPARSER_HPP_
#define SIMPLEMODELLANDMARKFORMATPARSER_HPP_

#include "imageio/LandmarkFormatParser.hpp"
#include "imageio/LandmarkCollection.hpp"
#include "imageio/ModelLandmark.hpp"
#include <vector>
#include <string>
#include <map>
#include <memory>

namespace imageio {

/**
 * Takes the path to a landmark file as input and returns a map with one
 * entry containing a LandmarkCollection with all the landmarks found.
 * The landmarks in the file need to be in the format 'name x y'.
 */
class SimpleModelLandmarkFormatParser : public LandmarkFormatParser {
public:

	/**
	 * Reads the landmark data for one single image and returns all its landmarks.
	 *
	 * @param[in] landmarkFilePath A path to a file containing landmarks.
	 * @return A map with one entry containing the basename of the
	 *         file and all the landmarks that are present.
	 */
	const std::map<boost::filesystem::path, LandmarkCollection> read(boost::filesystem::path landmarkFilePath);

private:
	/**
	 * Opens and parses a text file and returns a collection of all the landmarks it contains.
	 *
	 * @param[in] filename The file name of the file to parse.
	 * @return A collection of all the landmarks.
	 */
	LandmarkCollection parseFile(const std::string& filename);

	/**
	 * Parse a line in the form 'name x y' and returns a Landmark.
	 *
	 * @param[in] line The line with the landmark information to parse.
	 * @return A Landmark object.
	 */
	std::shared_ptr<ModelLandmark> parseLine(const std::string& line);
	
};

} /* namespace imageio */
#endif /* SIMPLEMODELLANDMARKFORMATPARSER_HPP_ */
