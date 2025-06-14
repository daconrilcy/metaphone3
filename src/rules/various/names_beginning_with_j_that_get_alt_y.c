#include "rules/various/names_beginning_with_j_that_get_alt_y.h"
#include "utils/string_utils.h"

#include <stdio.h>

bool Names_Beginning_With_J_That_Get_Alt_Y(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;

  if (StringAt(w, 0, 3, "JAN", "JON", "JAN", "JIN", "JEN", "") ||
      StringAt(w, 0, 4, "JUHL", "JULY", "JOEL", "JOHN", "JOSH", "JUDE", "JUNE",
               "JONI", "JULI", "JENA", "JUNG", "JINA", "JANA", "JENI", "JOEL",
               "JANN", "JONA", "JENE", "JULE", "JANI", "JONG", "JOHN", "JEAN",
               "JUNG", "JONE", "JARA", "JUST", "JOST", "JAHN", "JACO", "JANG",
               "JUDE", "JONE", "") ||
      StringAt(w, 0, 5, "JOANN", "JANEY", "JANAE", "JOANA", "JUTTA", "JULEE",
               "JANAY", "JANEE", "JETTA", "JOHNA", "JOANE", "JAYNA", "JANES",
               "JONAS", "JONIE", "JUSTA", "JUNIE", "JUNKO", "JENAE", "JULIO",
               "JINNY", "JOHNS", "JACOB", "JETER", "JAFFE", "JESKE", "JANKE",
               "JAGER", "JANIK", "JANDA", "JOSHI", "JULES", "JANTZ", "JEANS",
               "JUDAH", "JANUS", "JENNY", "JENEE", "JONAH", "JONAS", "JACOB",
               "JOSUE", "JOSEF", "JULES", "JULIE", "JULIA", "JANIE", "JANIS",
               "JENNA", "JANNA", "JEANA", "JENNI", "JEANE", "JONNA", "") ||
      StringAt(
          w, 0, 6, "JORDAN", "JORDON", "JOSEPH", "JOSHUA", "JOSIAH", "JOSPEH",
          "JUDSON", "JULIAN", "JULIUS", "JUNIOR", "JUDITH", "JOESPH", "JOHNIE",
          "JOANNE", "JEANNE", "JOANNA", "JOSEFA", "JULIET", "JANNIE", "JANELL",
          "JASMIN", "JANINE", "JOHNNY", "JEANIE", "JEANNA", "JOHNNA", "JOELLE",
          "JOVITA", "JOSEPH", "JONNIE", "JANEEN", "JANINA", "JOANIE", "JAZMIN",
          "JOHNIE", "JANENE", "JOHNNY", "JONELL", "JENELL", "JANETT", "JANETH",
          "JENINE", "JOELLA", "JOEANN", "JULIAN", "JOHANA", "JENICE", "JANNET",
          "JANISE", "JULENE", "JOSHUA", "JANEAN", "JAIMEE", "JOETTE", "JANYCE",
          "JENEVA", "JORDAN", "JACOBS", "JENSEN", "JOSEPH", "JANSEN", "JORDON",
          "JULIAN", "JAEGER", "JACOBY", "JENSON", "JARMAN", "JOSLIN", "JESSEN",
          "JAHNKE", "JACOBO", "JULIEN", "JOSHUA", "JEPSON", "JULIUS", "JANSON",
          "JACOBI", "JUDSON", "JARBOE", "JOHSON", "JANZEN", "JETTON", "JUNKER",
          "JONSON", "JAROSZ", "JENNER", "JAGGER", "JASMIN", "JEPSEN", "JORDEN",
          "JANNEY", "JUHASZ", "JERGEN", "JAKOB", "") ||
      StringAt(w, 0, 7, "JOHNSON", "JOHNNIE", "JASMINE", "JEANNIE", "JOHANNA",
               "JANELLE", "JANETTE", "JULIANA", "JUSTINA", "JOSETTE", "JOELLEN",
               "JENELLE", "JULIETA", "JULIANN", "JULISSA", "JENETTE", "JANETTA",
               "JOSELYN", "JONELLE", "JESENIA", "JANESSA", "JAZMINE", "JEANENE",
               "JOANNIE", "JADWIGA", "JOLANDA", "JULIANE", "JANUARY", "JEANICE",
               "JANELLA", "JEANETT", "JENNINE", "JOHANNE", "JOHNSIE", "JANIECE",
               "JOHNSON", "JENNELL", "JAMISON", "JANSSEN", "JOHNSEN", "JARDINE",
               "JAGGERS", "JURGENS", "JOURDAN", "JULIANO", "JOSEPHS", "JHONSON",
               "JOZWIAK", "JANICKI", "JELINEK", "JANSSON", "JOACHIM", "JANELLE",
               "JACOBUS", "JENNING", "JANTZEN", "JOHNNIE", "") ||
      StringAt(w, 0, 8, "JOSEFINA", "JEANNINE", "JULIANNE", "JULIANNA",
               "JONATHAN", "JONATHON", "JEANETTE", "JANNETTE", "JEANETTA",
               "JOHNETTA", "JENNEFER", "JULIENNE", "JOSPHINE", "JEANELLE",
               "JOHNETTE", "JULIEANN", "JOSEFINE", "JULIETTA", "JOHNSTON",
               "JACOBSON", "JACOBSEN", "JOHANSEN", "JOHANSON", "JAWORSKI",
               "JENNETTE", "JELLISON", "JOHANNES", "JASINSKI", "JUERGENS",
               "JARNAGIN", "JEREMIAH", "JEPPESEN", "JARNIGAN", "JANOUSEK",
               "") ||
      StringAt(w, 0, 9, "JOHNATHAN", "JOHNATHON", "JORGENSEN", "JEANMARIE",
               "JOSEPHINA", "JEANNETTE", "JOSEPHINE", "JEANNETTA", "JORGENSON",
               "JANKOWSKI", "JOHNSTONE", "JABLONSKI", "JOSEPHSON", "JOHANNSEN",
               "JURGENSEN", "JIMMERSON", "JOHANSSON", "") ||
      StringAt(w, 0, 10, "JAKUBOWSKI", ""))
  {

    return true;
  }
  return false;
}