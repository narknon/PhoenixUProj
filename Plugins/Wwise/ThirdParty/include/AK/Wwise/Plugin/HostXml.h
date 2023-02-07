/*******************************************************************************
The content of this file includes portions of the AUDIOKINETIC Wwise Technology
released in source code form as part of the SDK installer package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use this file in accordance with the end user license agreement provided 
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Apache License Usage

Alternatively, this file may be used under the Apache License, Version 2.0 (the 
"Apache License"); you may not use this file except in compliance with the 
Apache License. You may obtain a copy of the Apache License at 
http://www.apache.org/licenses/LICENSE-2.0.

Unless required by applicable law or agreed to in writing, software distributed
under the Apache License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
OR CONDITIONS OF ANY KIND, either express or implied. See the Apache License for
the specific language governing permissions and limitations under the License.

  Version: v2021.1.9  Build: 7847
  Copyright (c) 2006-2022 Audiokinetic Inc.
*******************************************************************************/

/**
 * \brief Wwise Authoring Plug-ins - API for XML-based persistence, as used in CustomData.
 * \file AK/Wwise/Plugin/HostXml.h
 */

#pragma once

#include "PluginInfoGenerator.h"

namespace AK
{
	namespace Wwise
	{
		namespace Plugin
		{
			/// 
			namespace XmlWhiteSpaceHandling
			{
				/// See MSDN documentation
				enum WhiteSpaceHandling
				{
					All,
					None,
					Significant
				};
			}

			/// Types of possible XML elements.  See MSDN documentation topics for XmlNodeType.
			namespace XmlNodeType
			{
				/// See MSDN documentation topics for XmlNodeType.
				/// MUST match XmlLite node types
				enum NodeType
				{
					Attribute = 2,
					CDATA = 4,
					Comment = 8,
					Document = 9,
					DocumentFragment = 11,
					DocumentType = 10,
					Element = 1,
					EndElement = 15,
					EndEntity = 16,
					Entity = 6,
					EntityReference = 5,
					None = 0,
					Notation = 12,
					ProcessingInstruction = 7,
					SignificantWhitespace = 14,
					Text = 3,
					Whitespace = 13,
					XmlDeclaration = 17
				};
			}
			namespace XmlWriteState
			{
				/// WriteState
				enum WriteState
				{
					Attribute,	///< Attribute
					Closed,		///< Closed	
					Content,	///< Content
					Element,	///< Element
					Prolog,		///< Prolog	
					Start		///< Start	
				};
			}

			/// Possible error codes when writing XML
			namespace XmlWriteReady
			{
				/// Possible error codes when writing XML
				enum WriteReady
				{
					Ready,				///< No error
					ErrorPathTooLong,	///< Path exceeds max length
					ErrorAccessDenied,	///< Cannot open file due to access permissions
					ErrorUnknown		///< Unknown error
				};
			}

			namespace XmlElementType
			{
				/// These element types have an impact when outputting in alternate formats such as JSON.
				enum ElementType
				{
					Map,		// Associative (Unique Keys)
					Array,		// Enumerative
					MultiMap	// Associative (Shared Keys)
				};
			};
		}
	}
}

/**
 * \brief API interface for XML-based plug-in persistence.
 * 
 * The XML plug-in persistence is useful when a plug-in provides custom data handling. Normally, plug-in data
 * is stored through the property sets (see \ref wwiseplugin_propertyset "PropertySet" and \ref wwiseplugin_objectstore "ObjectStore").
 * However, a plug-in might provide its own custom handling. For complex interfaces, it might be worthwhile to use the 
 * \ref wwiseplugin_complexproperty "CustomData" interface. Loading and saving can then be done through this XML interface.
 * 
 * The XML interface represents a cursor pointing to a node (element), alongside methods to navigate through
 * the hierarchy.
 * 
 * \aknote
 * 		One unique XML interface is provided for both reading and writing XML. Depending on the instance being
 * 		provided, it will allow reading or writing through this interface.
 * 
 * 		It can either be a \ref ak_wwise_plugin_host_xml_reader_instance_v1 or a
 * 		\ref ak_wwise_plugin_host_xml_writer_instance_v1.
 * \endaknote
 */
struct ak_wwise_plugin_host_xml_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	ak_wwise_plugin_host_xml_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_XML, 1)
	{}
	using ReaderInstance = ak_wwise_plugin_host_xml_reader_instance_v1;
	using WriterInstance = ak_wwise_plugin_host_xml_writer_instance_v1;
#endif

	/**
	 * \brief Returns the name of the current node being read.
	 * 
	 * \aknote
	 * 		The string is available until the next Host operation. If storing is required, a copy should be made
	 * 		at the earliest convenience.
	 * \endaknote
	 * 
	 * \param[in] in_this Current reader instance of this interface.
	 * \return The name of the current node. The buffer is owned by Authoring and is 
	 *   valid until the next API call.
	 */
	const char *(*GetName)(const struct ak_wwise_plugin_host_xml_reader_instance_v1* in_this);

	/**
	 * \brief Returns the type of the current node being read.
	 * 
	 * The type is equivalent to Microsoft Windows \c XmlNodeType. See MSDN documentation on
	 * \c XmlNodeType for further information.
	 * 
	 * \param[in] in_this Current reader instance of this interface.
	 * \return The type of the current node.
	 */
	AK::Wwise::Plugin::XmlNodeType::NodeType(*GetNodeType)(const struct ak_wwise_plugin_host_xml_reader_instance_v1* in_this);

	/**
	 * \brief Tests whether the current node being read is empty.
	 * 
	 * \param[in] in_this Current reader instance of this interface.
	 * \return true if the current node is empty.
	 */
	bool(*IsEmptyElement)(const struct ak_wwise_plugin_host_xml_reader_instance_v1* in_this);

	/**
	 * \brief Returns the value of the current node being read.
	 * 
	 * This returns the textual representation of the current node's value. What the XML parser considers
	 * to be a value might not be what is expected, as the final text could be comprised of multiple
	 * values.
	 * 
	 * For example, this \c Item node has three content elements: <tt>&lt;Item&gt;1&amp;number;3&lt;/Item&gt;</tt> 
	 * 
	 * For normal string retrieval, the \ref ReadElementString will actually return the value of an XML with
	 * proper parsing applied.
	 * 
	 * \aknote
	 * 		The string is available until the next Host operation. If storing is required, a copy should be made
	 * 		at the earliest convenience.
	 * \endaknote
	 * 
	 * \param[in] in_this Current reader instance of this interface.
	 * \return The value of the current node, an empty string if the value is empty.
	 *   The buffer is owned by Authoring and is valid until the next API call.
	 */
	const char *(*GetValue)(const struct ak_wwise_plugin_host_xml_reader_instance_v1* in_this);

	/**
	 * \brief Tests whether the end of file is reached while reading the XML.
	 * 
	 * The last valid node of the file is consdiered the end-of-file point. It can be
	 * \c SignificantWhitespace if the file ends with supplemental lines.
	 * 
	 * \param[in] in_this Current reader instance of this interface.
	 * \return true if the end of file is reached.
	 */
	bool(*IsEOF)(const struct ak_wwise_plugin_host_xml_reader_instance_v1* in_this);

	/**
	 * \brief Retrieves the line number that contains the start of the current node being read.
	 * 
	 * This is useful in some cases, where an error message might be written, or for debugging purposes.
	 * 
	 * \param[in] in_this Current reader instance of this interface.
	 * \return Current line number in the file.
	 */
	int(*GetLineNumber)(const struct ak_wwise_plugin_host_xml_reader_instance_v1* in_this);

	/**
	 * \brief Retrieves the column in the line that contains the start of the current node being read.
	 * 
	 * This is useful in some cases, where an error message might be written, or for debugging purposes.
	 * 
	 * \param[in] in_this Current reader instance of this interface.
	 * \return Current column number in the line.
	 */
	int(*GetLinePosition)(const struct ak_wwise_plugin_host_xml_reader_instance_v1* in_this);

	/**
	 * \brief Makes sure the cursor points to a content-type entity while reading XML.
	 * 
	 * If the node is not a content node, the reader skips ahead to the next content entity until the
	 * end of file. More specifically, it will skip over the following usual node types:
	 * - \c ProcessingInstruction
	 * - \c DocumentType
	 * - \c Comment
	 * - \c Whitespace
	 * - \c SignificantWhitespace
	 * 
	 * Content entities are specifically:
	 * - \c Text (Non-whitespace text)
	 * - \c CDATA
	 * - \c Element
	 * - \c EndElement
	 * - \c EndEntity
	 * - \c EntityReference
	 * 
	 * This method will also move to the element part of an \c Attribute.
	 * 
	 * \aknote
	 * 		This method is mostly a convenience and could be easily coded by a simple loop.
	 * 
	 * 		Once the current node hierarchy information is determined by proper use of
	 * 		\ref Read, MoveToContent will make sure to provide the actual content of the entity. If no
	 * 		content is available, it will return \ref AK::Wwise::Plugin::XmlNodeType::EndElement "EndElement"
	 * 		or \ref AK::Wwise::Plugin::XmlNodeType::EndEntity "EndEntity".
	 * \endaknote
	 * 
	 * \param[in] in_this Current reader instance of this interface.
	 * \return The new node type. \c None if the reader has reached the end of file.
	 */
	AK::Wwise::Plugin::XmlNodeType::NodeType(*MoveToContent)(struct ak_wwise_plugin_host_xml_reader_instance_v1* in_this);

	/**
	 * \brief Sets the reading pointer to the next node, recursively.
	 * 
	 * The node can be any entity type except \c SignificantWhitespace.
	 * 
	 * \param[in] in_this Current reader instance of this interface.
	 * \return false if the end of file is reached.
	 */
	bool(*Read)(struct ak_wwise_plugin_host_xml_reader_instance_v1* in_this);

	/**
	 * \brief Reads simple text-only elements, and increments the pointer.
	 * 
	 * Since strings can span multiple content elements, this method will read all the sequential string-like
	 * elements and append them, returning one simple string. This function also works with empty nodes and
	 * multiple lines.
	 * 
	 * If no processing or incrementing is warranted, \ref Read, \ref MoveToContent and \ref GetValue
	 * should be used instead.
	 * 
	 * This method goes past the ending element node, or the equivalent of calling Read once more.
	 * 
	 * \aknote
	 * 		The string is available until the next Host operation. If storing is required, a copy should be made
	 * 		at the earliest convenience.
	 * \endaknote
	 * 
	 * \param[in] in_this Current reader instance of this interface.
	 * \return The string of the current nodes, an empty string if the value is empty.
	 *   The buffer is owned by Authoring and is valid until the next API call.
	 */
	const char *(*ReadElementString)(struct ak_wwise_plugin_host_xml_reader_instance_v1* in_this);

	/**
	 * \brief Reads all the contents of an Element or Attribute as a string, including markup. Increments the pointer.
	 * 
	 * This returns the raw contents of the file except the enclosing elements. It can be considered the
	 * equivalent of \ref ReadElementString , but will also return raw XML tags.
	 * 
	 * An empty string will be returned if no content is available.
	 * 
	 * \aknote
	 * 		The string is available until the next Host operation. If storing is required, a copy should be made
	 * 		at the earliest convenience.
	 * \endaknote
	 * 
	 * \param[in] in_this Current reader instance of this interface.
	 * \param[out] out_csXml All the XML content, including markup, in the current node.
	 *   The buffer is owned by Authoring and is valid until the next API call.
	 */
	void(*ReadInnerXml)(struct ak_wwise_plugin_host_xml_reader_instance_v1* in_this, const char ** out_csXml);

	/**
	 * \brief Reads the Element or Attribute as a string, including markup. Increments the pointer.
	 * 
	 * This returns the raw contents of the file including the enclosing elements. It can be considered the
	 * equivalent of \ref ReadElementString , but will also return raw XML tags.
	 * 
	 * An empty string will be returned if no content is available.
	 * 
	 * \aknote
	 * 		The string is available until the next Host operation. If storing is required, a copy should be made
	 * 		at the earliest convenience.
	 * \endaknote
	 * 
	 * \param[in] in_this Current reader instance of this interface.
	 * \param[out] out_csXml All the XML content, including markup and enclosing tags, of the current node.
	 *   The buffer is owned by Authoring and is valid until the next API call.
	 */
	void(*ReadOuterXml)(struct ak_wwise_plugin_host_xml_reader_instance_v1* in_this, const char ** out_csXml);

	/**
	 * \brief Sets the reading pointer past the current node, skipping any inner content.
	 * 
	 * \param[in] in_this Current reader instance of this interface.
	 * \return false if the end of file is reached.
	 */
	void(*Skip)(struct ak_wwise_plugin_host_xml_reader_instance_v1* in_this);

	/**
	 * \brief Reads the value of a particular attribute under the current node.
	 * 
	 * \param[in] in_this Current reader instance of this interface.
	 * \param[in] in_rcsAttributeName The attribute name
	 * \param[out] out_rcsValue The attribute value.
	 *   The buffer is owned by Authoring and is valid until the next API call.
	 * \return true if the value exists.
	 */
	bool(*GetAttribute)(
		struct ak_wwise_plugin_host_xml_reader_instance_v1* in_this,
		const char * in_rcsAttributeName,
		const char ** out_rcsValue
	);


	/**
	 * \brief Determines if the writer is ready to be used.
	 * \internal
	 * 
	 * For plug-ins, the XML writer is always ready.
	 * 
	 * \param[in] in_this Current writer instance of this interface.
	 * \return true if ready.
	 */
	bool(*IsReady)(const struct ak_wwise_plugin_host_xml_writer_instance_v1* in_this);

	/**
	 * \brief Determines the state of readiness of the writer.
	 * \internal
	 * 
	 * For plug-ins, the XML writer is always ready.
	 * 
	 * \param[in] in_this Current writer instance of this interface.
	 * \return \c Ready if ready.
	 */
	AK::Wwise::Plugin::XmlWriteReady::WriteReady(*GetReadyState)(const struct ak_wwise_plugin_host_xml_writer_instance_v1* in_this);

	/**
	 * \brief Appending a first XML writer to a second XML writer.
	 * \internal
	 * 
	 * For plug-ins, there aren't multiple writer instances.
	 * 
	 * \param[in] in_this Current writer instance of this interface.
	 * \param[in] in_pWriterToAppend Second writer instance to append to our current instance.
	 * \return true if successful
	 */
	bool(*Append)(struct ak_wwise_plugin_host_xml_writer_instance_v1* in_this, struct ak_wwise_plugin_host_xml_writer_instance_v1* in_pWriterToAppend);

	/**
	 * \brief Retrieves the state of the node the writer is currently populating.
	 * \internal
	 * 
	 * For plug-ins, the states are very simple.
	 * 
	 * \param[in] in_this Current writer instance of this interface.
	 * \return The current write state.
	 */
	AK::Wwise::Plugin::XmlWriteState::WriteState(*GetWriteState)(const struct ak_wwise_plugin_host_xml_writer_instance_v1* in_this);

	/**
	 * \brief Starts a new XML document.
	 * \internal
	 * 
	 * For plug-ins, the XML document is already created.
	 * 
	 * \param[in] in_this Current writer instance of this interface.
	 */
	void(*WriteStartDocument)(struct ak_wwise_plugin_host_xml_writer_instance_v1* in_this);

	/**
	 * \brief Ends a completed XML document.
	 * \internal
	 * 
	 * For plug-ins, the XML document will be closed for you.
	 * 
	 * \param[in] in_this Current writer instance of this interface.
	 */
	void(*WriteEndDocument)(struct ak_wwise_plugin_host_xml_writer_instance_v1* in_this);

	/**
	 * \brief Creates a new inner node.
	 * 
	 * You should close this element with \ref WriteEndElement.
	 * 
	 * \param[in] in_this Current writer instance of this interface.
	 * \param[in] in_rcsElementName Node name, as retrieved on the reader with \ref GetName.
	 * \param[in] in_eType Ignored.
	 */
	void(*WriteStartElement)(
		struct ak_wwise_plugin_host_xml_writer_instance_v1* in_this,
		const char * in_rcsElementName,
		AK::Wwise::Plugin::XmlElementType::ElementType in_eType
	);

	/**
	 * \brief Closes the previous node.
	 * 
	 * \param[in] in_this Current writer instance of this interface.
	 */
	void(*WriteEndElement)(struct ak_wwise_plugin_host_xml_writer_instance_v1* in_this);

	/**
	 * \brief Adds an attribute to the current node.
	 * 
	 * \param[in] in_this Current writer instance of this interface.
	 * \param[in] in_rcsAttribute Attribute name.
	 * \param[in] in_rcsValue Attribute value.
	 */
	void(*WriteAttributeString)(
		struct ak_wwise_plugin_host_xml_writer_instance_v1* in_this,
		const char * in_rcsAttribute,
		const char * in_rcsValue
	);

	/**
	 * \brief Appends a string as value to the current node.
	 * 
	 * \param[in] in_this Current writer instance of this interface.
	 * \param[in] in_rcsValue Node value.
	 */
	void(*WriteString)(
		struct ak_wwise_plugin_host_xml_writer_instance_v1* in_this,
		const char * in_rcsValue
	);

	/**
	 * \brief Appends a raw CDATA string as value to the current node.
	 * 
	 * No processing of the CDATA is done.
	 * 
	 * \param[in] in_this Current writer instance of this interface.
	 * \param[in] in_rcsValue Node's raw value to be inserted insde a `<![CDATA[...]]>`
	 */
	void(*WriteCData)(
		struct ak_wwise_plugin_host_xml_writer_instance_v1* in_this,
		const char * in_rcsValue
	);

	/**
	 * \brief Appends a raw string at this precise point of the XML file.
	 * 
	 * No processing of the data is done.
	 * 
	 * \param[in] in_this Current writer instance of this interface.
	 * \param[in] in_rcsValue Node's raw value to be inserted.
	 */
	void(*WriteRaw)(
		struct ak_wwise_plugin_host_xml_writer_instance_v1* in_this,
		const char * in_rcsValue
	);

};
#define AK_WWISE_PLUGIN_HOST_XML_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_XML, 1)
#define AK_WWISE_PLUGIN_HOST_XML_V1_CTOR() \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_HOST_XML_V1_ID() \
}


#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		using CHostXml = ak_wwise_plugin_host_xml_v1;
		
		/// \copydoc ak_wwise_plugin_host_xml_v1
		class XmlReader : public CBaseInstanceGlue<CHostXml, CHostXml::ReaderInstance>
		{
		public:
			using Interface = CHostXml;

			/**
			 * \brief The interface type, as requested by this plug-in.
			 */
			enum : InterfaceTypeValue
			{
				/**
				 * \brief The interface type, as requested by this plug-in.
				 */
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_XML
			};
			/**
			 * \brief The interface version, as requested by this plug-in.
			 */
			enum : InterfaceVersion
			{
				/**
				 * \brief The interface version, as requested by this plug-in.
				 */
				k_interfaceVersion = 1
			};

			/**
			 * \brief Returns the name of the current node being read.
			 * 
			 * \aknote
			 * 		The string is available until the next Host operation. If storing is required, a copy should be made
			 * 		at the earliest convenience.
			 * \endaknote
			 * 
			 * \return The name of the current node.
			 *   The buffer is owned by Authoring and is valid until the next API call.
			 */
			inline const char * GetName() const { return g_cinterface->GetName(this); }

			/**
			 * \brief Returns the type of the current node being read.
			 * 
			 * The type is equivalent to Microsoft Windows \c XmlNodeType. See MSDN documentation on
			 * \c XmlNodeType for further information.
			 * 
			 * \return The type of the current node.
			 */
			inline AK::Wwise::Plugin::XmlNodeType::NodeType GetNodeType() const { return g_cinterface->GetNodeType(this); }

			/**
			 * \brief Tests whether the current node being read is empty.
			 * 
			 * \return true if the current node is empty.
			 */
			inline bool IsEmptyElement() const { return MKBOOL(g_cinterface->IsEmptyElement(this)); }

			/**
			 * \brief Returns the value of the current node being read.
			 * 
			 * This returns the textual representation of the current node's value. What the XML parser considers
			 * to be a value might not be what is expected, as the final text could be comprised of multiple
			 * values.
			 * 
			 * For example, this \c Item node has three content elements: <tt>&lt;Item&gt;1&amp;number;3&lt;/Item&gt;</tt> 
			 * 
			 * For normal string retrieval, the \ref ReadElementString will actually return the value of an XML with
			 * proper parsing applied.
			 * 
			 * \aknote
			 * 		The string is available until the next Host operation. If storing is required, a copy should be made
			 * 		at the earliest convenience.
			 * \endaknote
			 * 
			 * \return The value of the current node, an empty string if the value is empty.
			 *   The buffer is owned by Authoring and is valid until the next API call.
			 */
			inline const char * GetValue() const { return g_cinterface->GetValue(this); }

			/**
			 * \brief Tests whether the end of file is reached while reading the XML.
			 * 
			 * The last valid node of the file is consdiered the end-of-file point. It can be
			 * \c SignificantWhitespace if the file ends with supplemental lines.
			 * 
			 * \return true if the end of file is reached.
			 */
			inline bool IsEOF() const { return MKBOOL(g_cinterface->IsEOF(this)); }

			/**
			 * \brief Retrieves the line number that contains the start of the current node being read.
			 * 
			 * This is useful in some cases, where an error message might be written, or for debugging purposes.
			 * 
			 * \return Current line number in the file.
			 */
			inline int GetLineNumber() const { return g_cinterface->GetLineNumber(this); }

			/**
			 * \brief Retrieves the column in the line that contains the start of the current node being read.
			 * 
			 * This is useful in some cases, where an error message might be written, or for debugging purposes.
			 * 
			 * \return Current column number in the line.
			 */
			inline int GetLinePosition() const { return g_cinterface->GetLinePosition(this); }

			/**
			 * \brief Makes sure the cursor points to a content-type entity while reading XML.
			 * 
			 * If the node is not a content node, the reader skips ahead to the next content entity until the
			 * end of file. More specifically, it will skip over the following usual node types:
			 * - \c ProcessingInstruction
			 * - \c DocumentType
			 * - \c Comment
			 * - \c Whitespace
			 * - \c SignificantWhitespace
			 * 
			 * Content entities are specifically:
			 * - \c Text (Non-whitespace text)
			 * - \c CDATA
			 * - \c Element
			 * - \c EndElement
			 * - \c EndEntity
			 * - \c EntityReference
			 * 
			 * This method will also move to the element part of an \c Attribute.
			 * 
			 * \aknote
			 * 		This method is mostly a convenience and could be easily coded by a simple loop.
			 * 
			 * 		Once the current node hierarchy information is determined by proper use of
			 * 		\ref Read, MoveToContent will make sure to provide the actual content of the entity. If no
			 * 		content is available, it will return \ref AK::Wwise::Plugin::XmlNodeType::EndElement "EndElement"
			 * 		or \ref AK::Wwise::Plugin::XmlNodeType::EndEntity "EndEntity".
			 * \endaknote
			 * 
			 * \return The new node type. \c None if the reader has reached the end of file.
			 */
			inline AK::Wwise::Plugin::XmlNodeType::NodeType MoveToContent() { return g_cinterface->MoveToContent(this); }

			/**
			 * \brief Sets the reading pointer to the next node, recursively.
			 * 
			 * The node can be any entity type except \c SignificantWhitespace.
			 * 
			 * \return false if the end of file is reached.
			 */
			inline bool Read() { return MKBOOL(g_cinterface->Read(this)); }

			/**
			 * \brief Reads simple text-only elements, and increments the pointer.
			 * 
			 * Since strings can span multiple content elements, this method will read all the sequential string-like
			 * elements and append them, returning one simple string. This function also works with empty nodes and
			 * multiple lines.
			 * 
			 * If no processing or incrementing is warranted, \ref Read, \ref MoveToContent and \ref GetValue
			 * should be used instead.
			 * 
			 * This method goes past the ending element node, or the equivalent of calling Read once more.
			 * 
			 * \aknote
			 * 		The string is available until the next Host operation. If storing is required, a copy should be made
			 * 		at the earliest convenience.
			 * \endaknote
			 * 
			 * \return The string of the current nodes, an empty string if the value is empty.
			 *   The buffer is owned by Authoring and is valid until the next API call.
			 */
			inline const char * ReadElementString() { return g_cinterface->ReadElementString(this); }

			/**
			 * \brief Reads all the contents of an Element or Attribute as a string, including markup. Increments the pointer.
			 * 
			 * This returns the raw contents of the file except the enclosing elements. It can be considered the
			 * equivalent of \ref ReadElementString , but will also return raw XML tags.
			 * 
			 * An empty string will be returned if no content is available.
			 * 
			 * \aknote
			 * 		The string is available until the next Host operation. If storing is required, a copy should be made
			 * 		at the earliest convenience.
			 * \endaknote
			 * 
			 * \param[out] out_csXml All the XML content, including markup, in the current node.
			 *   The buffer is owned by Authoring and is valid until the next API call.
			 */
			inline void ReadInnerXml(const char *& out_csXml) { g_cinterface->ReadInnerXml(this, &out_csXml); }

			/**
			 * \brief Reads the Element or Attribute as a string, including markup. Increments the pointer.
			 * 
			 * This returns the raw contents of the file including the enclosing elements. It can be considered the
			 * equivalent of \ref ReadElementString , but will also return raw XML tags.
			 * 
			 * An empty string will be returned if no content is available.
			 * 
			 * \aknote
			 * 		The string is available until the next Host operation. If storing is required, a copy should be made
			 * 		at the earliest convenience.
			 * \endaknote
			 * 
			 * \param[out] out_csXml All the XML content, including markup and enclosing tags, of the current node.
			 *   The buffer is owned by Authoring and is valid until the next API call.
			 */
			inline void ReadOuterXml(const char *& out_csXml) { g_cinterface->ReadOuterXml(this, &out_csXml); }

			/**
			 * \brief Sets the reading pointer past the current node, skipping any inner content.
			 * 
			 * \return false if the end of file is reached.
			 */
			inline void Skip() { g_cinterface->Skip(this); }

			/**
			 * \brief Reads the value of a particular attribute under the current node.
			 * 
			 * \param[in] in_rcsAttributeName The attribute name
			 * \param[out] out_rcsValue The attribute value.
			 *   The buffer is owned by Authoring and is valid until the next API call.
			 * \return true if the value exists.
			 */
			inline bool GetAttribute(const char * in_rcsAttributeName, const char *& out_rcsValue) { return MKBOOL(g_cinterface->GetAttribute(this, in_rcsAttributeName, &out_rcsValue)); }
		};

		/// \copydoc ak_wwise_plugin_host_xml_v1
		class XmlWriter : public CBaseInstanceGlue<CHostXml, CHostXml::WriterInstance>
		{
		public:
			using Interface = CHostXml;

			/**
			 * \brief The interface type, as requested by this plug-in.
			 */
			enum : InterfaceTypeValue
			{
				/**
				 * \brief The interface type, as requested by this plug-in.
				 */
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_XML
			};
			/**
			 * \brief The interface version, as requested by this plug-in.
			 */
			enum : InterfaceVersion
			{
				/**
				 * \brief The interface version, as requested by this plug-in.
				 */
				k_interfaceVersion = 1
			};

			/**
			 * \brief Determines if the writer is ready to be used.
			 * \internal
			 * 
			 * For plug-ins, the XML writer is always ready.
			 * 
			 * \return true if ready.
			 */
			inline bool IsReady() const { return MKBOOL(g_cinterface->IsReady(this)); }

			/**
			 * \brief Determines the state of readiness of the writer.
			 * \internal
			 * 
			 * For plug-ins, the XML writer is always ready.
			 * 
			 * \return \c Ready if ready.
			 */
			inline AK::Wwise::Plugin::XmlWriteReady::WriteReady GetReadyState() const { return g_cinterface->GetReadyState(this); }

			/**
			 * \brief Appending a first XML writer to a second XML writer.
			 * \internal
			 * 
			 * For plug-ins, there aren't multiple writer instances.
			 * 
			 * \param[in] in_writerToAppend Second writer instance to append to our current instance.
			 * \return true if successful
			 */
			inline bool Append(XmlWriter& in_writerToAppend) { return MKBOOL(g_cinterface->Append(this, &in_writerToAppend)); }

			/**
			 * \brief Retrieves the state of the node the writer is currently populating.
			 * \internal
			 * 
			 * For plug-ins, the states are very simple.
			 * 
			 * \param[in] in_this Current writer instance of this interface.
			 * \return The current write state.
			 */
			inline AK::Wwise::Plugin::XmlWriteState::WriteState GetWriteState() const { return g_cinterface->GetWriteState(this); }

			/**
			 * \brief Starts a new XML document.
			 * \internal
			 * 
			 * For plug-ins, the XML document is already created.
			 */
			inline void WriteStartDocument() { g_cinterface->WriteStartDocument(this); }

			/**
			 * \brief Ends a completed XML document.
			 * \internal
			 * 
			 * For plug-ins, the XML document will be closed for you.
			 */
			inline void WriteEndDocument() { g_cinterface->WriteEndDocument(this); }

			/**
			 * \brief Creates a new inner node.
			 * 
			 * You should close this element with \ref WriteEndElement.
			 * 
			 * \param[in] in_rcsElementName Node name, as retrieved on the reader with \ref AK::Wwise::Plugin::XmlReader::GetName "GetName".
			 * \param[in] in_eType Ignored.
			 */
			inline void WriteStartElement(const char * in_rcsElementName, AK::Wwise::Plugin::XmlElementType::ElementType in_eType) { g_cinterface->WriteStartElement(this, in_rcsElementName, in_eType); }

			/**
			 * \brief Closes the previous node.
			 */
			inline void WriteEndElement() { g_cinterface->WriteEndElement(this); }

			/**
			 * \brief Adds an attribute to the current node.
			 * 
			 * \param[in] in_rcsAttribute Attribute name.
			 * \param[in] in_rcsValue Attribute value.
			 */
			inline void WriteAttributeString(const char * in_rcsAttribute, const char * in_rcsValue) { g_cinterface->WriteAttributeString(this, in_rcsAttribute, in_rcsValue); }

			/**
			 * \brief Appends a string as value to the current node.
			 * 
			 * \param[in] in_rcsValue Node value.
			 */
			inline void WriteString(const char * in_rcsValue) { g_cinterface->WriteString(this, in_rcsValue); }

			/**
			 * \brief Appends a raw CDATA string as value to the current node.
			 * 
			 * No processing of the CDATA is done.
			 * 
			 * \param[in] in_rcsValue Node's raw value to be inserted inside a `<![CDATA[...]]>`
			 */
			inline void WriteCData(const char * in_rcsValue) { g_cinterface->WriteCData(this, in_rcsValue); }

			/**
			 * \brief Appends a raw string at this precise point of the XML file.
			 * 
			 * No processing of the data is done.
			 * 
			 * \param[in] in_rcsValue Node's raw value to be inserted.
			 */
			inline void WriteRaw(const char * in_rcsValue) { g_cinterface->WriteRaw(this, in_rcsValue); }

			/// Use this class to handle the WriteStartElement/WriteEndElement pair automatically in a C++ scope.
			class AutoStartEndElement final
			{
			public:

				/// Calls WriteStartElement automatically
				AutoStartEndElement( const char * in_rcsElementName, XmlWriter* in_pWriter, AK::Wwise::Plugin::XmlElementType::ElementType in_eType = AK::Wwise::Plugin::XmlElementType::Map )
					: m_pWriter( in_pWriter )
				{
					m_pWriter->WriteStartElement( in_rcsElementName, in_eType );
				}

				AutoStartEndElement( const char * in_rcsElementName, XmlWriter& in_pWriter, AK::Wwise::Plugin::XmlElementType::ElementType in_eType = AK::Wwise::Plugin::XmlElementType::Map )
					: m_pWriter( &in_pWriter )
				{
					m_pWriter->WriteStartElement( in_rcsElementName, in_eType );
				}

				/// Calls WriteEndElement automatically
				~AutoStartEndElement()
				{
					m_pWriter->WriteEndElement();
				}

			private:
				XmlWriter* m_pWriter;
			};
		};

		/**
		 * \brief Requests the XML processing interface.
		 * 
		 * Deriving your plug-in class from RequestXml will automatically request
		 * XmlReader and XmlWriter interfaces. This is useful for
		 * CustomData loading and saving. You must derive from this interface
		 * in order to use the provided functions.
		 * 
		 * \aknote The RequestXml class is automatically derived when providing
		 * AK::Wwise::Plugin::CustomData in C++. \endaknote
		 */
		using RequestXml = RequestedHostInterface<XmlReader>;

	} // of namespace V1

	/// Latest version of the C XML interface.
	using CHostXml = V1::CHostXml;
	/// Latest version of the C++ XmlReader interface.
	using XmlReader = V1::XmlReader;
	/// Latest version of the C++ XmlWriter interface.
	using XmlWriter = V1::XmlWriter;
	/// Latest version of the requested C++ XML interface.
	using RequestXml = V1::RequestXml;

	AK_WWISE_PLUGIN_SPECIALIZE_HOST_INTERFACE_NO_BASE_INSTANCE(XmlReader, xmlTextReader);
	AK_WWISE_PLUGIN_SPECIALIZE_HOST_INTERFACE_NO_BASE_INSTANCE(XmlWriter, xmlTextWriter);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(XmlReader);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(XmlReader);

	// This uses the same interface than XmlReader so no need to specialize it twice.
	// AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(XmlWriter);
	// AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(XmlWriter);

} // of namespace AK::Wwise::Plugin
#endif
