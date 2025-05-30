#include "rules/various/germanic_or_slavic_name_beginning_with_w.h"
#include "utils/string_utils.h"

bool Germanic_Or_Slavic_Name_Beginning_With_W(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;

  if (StringAt(w, 0, 3, "WEE", "WIX", "WAX", "") ||
      StringAt(w, 0, 4, "WOLF", "WEIS", "WAHL", "WALZ", "WEIL", "WERT", "WINE",
               "WILK", "WALT", "WOLL", "WADA", "WULF", "WEHR", "WURM", "WYSE",
               "WENZ", "WIRT", "WOLK", "WEIN", "WYSS", "WASS", "WANN", "WINT",
               "WINK", "WILE", "WIKE", "WIER", "WELK", "WISE", "") ||
      StringAt(w, 0, 5, "WIRTH", "WIESE", "WITTE", "WENTZ", "WOLFF", "WENDT",
               "WERTZ", "WILKE", "WALTZ", "WEISE", "WOOLF", "WERTH", "WEESE",
               "WURTH", "WINES", "WARGO", "WIMER", "WISER", "WAGER", "WILLE",
               "WILDS", "WAGAR", "WERTS", "WITTY", "WIENS", "WIEBE", "WIRTZ",
               "WYMER", "WULFF", "WIBLE", "WINER", "WIEST", "WALKO", "WALLA",
               "WEBRE", "WEYER", "WYBLE", "WOMAC", "WILTZ", "WURST", "WOLAK",
               "WELKE", "WEDEL", "WEIST", "WYGAN", "WUEST", "WEISZ", "WALCK",
               "WEITZ", "WYDRA", "WANDA", "WILMA", "WEBER", "") ||
      StringAt(
          w, 0, 6, "WETZEL", "WEINER", "WENZEL", "WESTER", "WALLEN", "WENGER",
          "WALLIN", "WEILER", "WIMMER", "WEIMER", "WYRICK", "WEGNER", "WINNER",
          "WESSEL", "WILKIE", "WEIGEL", "WOJCIK", "WENDEL", "WITTER", "WIENER",
          "WEISER", "WEXLER", "WACKER", "WISNER", "WITMER", "WINKLE", "WELTER",
          "WIDMER", "WITTEN", "WINDLE", "WASHER", "WOLTER", "WILKEY", "WIDNER",
          "WARMAN", "WEYANT", "WEIBEL", "WANNER", "WILKEN", "WILTSE", "WARNKE",
          "WALSER", "WEIKEL", "WESNER", "WITZEL", "WROBEL", "WAGNON", "WINANS",
          "WENNER", "WOLKEN", "WILNER", "WYSONG", "WYCOFF", "WUNDER", "WINKEL",
          "WIDMAN", "WELSCH", "WEHNER", "WEIGLE", "WETTER", "WUNSCH", "WHITTY",
          "WAXMAN", "WILKER", "WILHAM", "WITTIG", "WITMAN", "WESTRA", "WEHRLE",
          "WASSER", "WILLER", "WEGMAN", "WARFEL", "WYNTER", "WERNER", "WAGNER",
          "WISSER", "") ||
      StringAt(w, 0, 7, "WISEMAN", "WINKLER", "WILHELM", "WELLMAN", "WAMPLER",
               "WACHTER", "WALTHER", "WYCKOFF", "WEIDNER", "WOZNIAK", "WEILAND",
               "WILFONG", "WIEGAND", "WILCHER", "WIELAND", "WILDMAN", "WALDMAN",
               "WORTMAN", "WYSOCKI", "WEIDMAN", "WITTMAN", "WIDENER", "WOLFSON",
               "WENDELL", "WEITZEL", "WILLMAN", "WALDRUP", "WALTMAN", "WALCZAK",
               "WEIGAND", "WESSELS", "WIDEMAN", "WOLTERS", "WIREMAN", "WILHOIT",
               "WEGENER", "WOTRING", "WINGERT", "WIESNER", "WAYMIRE", "WHETZEL",
               "WENTZEL", "WINEGAR", "WESTMAN", "WYNKOOP", "WALLICK", "WURSTER",
               "WINBUSH", "WILBERT", "WALLACH", "WYNKOOP", "WALLICK", "WURSTER",
               "WINBUSH", "WILBERT", "WALLACH", "WEISSER", "WEISNER", "WINDERS",
               "WILLMON", "WILLEMS", "WIERSMA", "WACHTEL", "WARNICK", "WEIDLER",
               "WALTRIP", "WHETSEL", "WHELESS", "WELCHER", "WALBORN", "WILLSEY",
               "WEINMAN", "WAGAMAN", "WOMMACK", "WINGLER", "WINKLES", "WIEDMAN",
               "WHITNER", "WOLFRAM", "WARLICK", "WEEDMAN", "WHISMAN", "WINLAND",
               "WEESNER", "WARTHEN", "WETZLER", "WENDLER", "WALLNER", "WOLBERT",
               "WITTMER", "WISHART", "WILLIAM", "") ||
      StringAt(w, 0, 8, "WESTPHAL", "WICKLUND", "WEISSMAN", "WESTLUND",
               "WOLFGANG", "WILLHITE", "WEISBERG", "WALRAVEN", "WOLFGRAM",
               "WILHOITE", "WECHSLER", "WENDLING", "WESTBERG", "WENDLAND",
               "WININGER", "WHISNANT", "WESTRICK", "WESTLING", "WESTBURY",
               "WEITZMAN", "WEHMEYER", "WEINMANN", "WISNESKI", "WHELCHEL",
               "WEISHAAR", "WAGGENER", "WALDROUP", "WESTHOFF", "WIEDEMAN",
               "WASINGER", "WINBORNE", "") ||
      StringAt(w, 0, 9, "WHISENANT", "WEINSTEIN", "WESTERMAN", "WASSERMAN",
               "WITKOWSKI", "WEINTRAUB", "WINKELMAN", "WINKFIELD", "WANAMAKER",
               "WIECZOREK", "WIECHMANN", "WOJTOWICZ", "WALKOWIAK", "WEINSTOCK",
               "WILLEFORD", "WARKENTIN", "WEISINGER", "WINKLEMAN", "WILHEMINA",
               "") ||
      StringAt(w, 0, 10, "WISNIEWSKI", "WUNDERLICH", "WHISENHUNT", "WEINBERGER",
               "WROBLEWSKI", "WAGUESPACK", "WEISGERBER", "WESTERVELT",
               "WESTERLUND", "WASILEWSKI", "WILDERMUTH", "WESTENDORF",
               "WESOLOWSKI", "WEINGARTEN", "WINEBARGER", "WESTERBERG",
               "WANNAMAKER", "WEISSINGER", "") ||
      StringAt(w, 0, 11, "WALDSCHMIDT", "WEINGARTNER", "WINEBRENNER", "") ||
      StringAt(w, 0, 12, "WOLFENBARGER", "") ||
      StringAt(w, 0, 13, "WOJCIECHOWSKI", "")) {
    return true;
  }

  return false;
}