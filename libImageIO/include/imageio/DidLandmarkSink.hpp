/*
 * DidLandmarkSink.hpp
 *
 *  Created on: 05.04.2014
 *      Author: Patrik Huber
 */
#pragma once

#ifndef DIDLANDMARKSINK_HPP_
#define DIDLANDMARKSINK_HPP_

#include "imageio/NamedLandmarkSink.hpp"

#ifdef WIN32
	#define BOOST_ALL_DYN_LINK	// Link against the dynamic boost lib. Seems to be necessary because we use /MD, i.e. link to the dynamic CRT.
	#define BOOST_ALL_NO_LIB	// Don't use the automatic library linking by boost with VS2010 (#pragma ...). Instead, we specify everything in cmake.
#endif
#include "boost/filesystem/path.hpp"

namespace imageio {

class LandmarkCollection;

/**
 * Sink for landmark collections where each landmark
 * is saved to a separate file in the Surrey DID
 * format. Each line is 'x y vertexId'.
 * TODO/Note: x and y are ints? What about float? CHECK!
 */
class DidLandmarkSink : public NamedLandmarkSink {
public:

	/**
	 * Adds a landmark collection and saves it to the given file.
	 *
	 * @param[in] collection The landmark collection.
	 * @param[in] filename The file to which to save the landmarks. The current file extension will be replaced by '.did', or, if none given, it will be added.
	 */
	void add(const LandmarkCollection& collection, boost::filesystem::path filename);
};

} /* namespace imageio */
#endif /* DIDLANDMARKSINK_HPP_ */
