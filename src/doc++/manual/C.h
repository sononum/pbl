/** A derived class.
    Here we show multiple inheritance from two docified classes.
    This example shows how to structure the members of a class, if desired.

    This is how this documentation has been generated:
    \begin{verbatim}
    /** A derived class.
        Here we show multiple inheritance from two docified classes.
        This example shows how to structure the members of a class, if desired.

        This is how this documentation has been generated:
    * /

    class Derived_Class : public CommonBase, protected Intermediate {
     public:
      /**@name parameters * /
      //@{
      /// the first parameter
      double a;
      /// a second parameter
      int b;
      //@}

      /**@name methods * /
      //@{
      /// constructor
      /** This constructor takes two arguments, just for the sake of
          demonstrating how documented members are displayed by DOC++.
          @param a this is good for many things
          @param b this is good for nothing
      * /
      DerivedClass(double a, int b);
      /// destructor
      ~DerivedClass();
      //@}
    };
    \end{verbatim}
*/
class Derived_Class : public CommonBase, protected Intermediate
{
 public:
  /**@name parameters */
  //@{
  /// the first parameter
  double a;
  /// a second parameter
  int b;
  //@}

  /**@name methods */
  //@{
  /** Constructor.
      This constructor takes two arguments, just for the sake of
      demonstrating how documented members are displayed by DOC++.
      @param a this is good for many things
      @param b this is good for nothing
   */
   Derived_Class(double a, int b);
   /// destructor
   ~Derived_Class();
   //@}
};

/** A global function.
    As promised, not only classes and members can be documented with DOC++.
    This is an example for how to document global scope functions. You'll
    notice that there is no technical difference to documenting member
    functions. The same applies to variables or macros.

    This is how this documentation has been generated:
    \begin{verbatim}
	/** A global function.
	    As promised, not only classes and members can be documented with DOC++.
	    This is an example for how to document global scope functions.
	    You'll notice that there is no technical difference to documenting
	    member functions. The same applies to variables or macros.

	    @param c reference to input data object
	    @return whatever
	    @author Snoopy
	    @version 3.3.12
	    @see Derived_Class
	 * /

    int	function(const DerivedClass& c);
    \end{verbatim}

    @param c reference to input data object
    @return whatever
    @author Snoopy
    @version 3.3.12
    @see Derived_Class
*/
int function(const DerivedClass& c);
