/** Just to make the class graph look more interesting.
    Here we show multiple inheritance from one docified class and a nondocified
    one.

    This is how this documentation has been generated:
    \begin{verbatim}
    /** Just to make the class graph look more interesting.
        Here we show multiple inheritance from one docified class and a nondocified
        one.

        This is how this documentation has been generated:
    * /

    class Intermediate : public CommonBase, public NotDocified {
      };
    \end{verbatim}
*/
class Intermediate : public CommonBase, public NotDocified
{
};
