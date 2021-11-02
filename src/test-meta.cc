/*
 * Copyright © 2019  Facebook, Inc.
 *
 *  This is part of HarfBuzz, a text shaping library.
 *
 * Permission is hereby granted, without written agreement and without
 * license or royalty fees, to use, copy, modify, and distribute this
 * software and its documentation for any purpose, provided that the
 * above copyright notice and the following two paragraphs appear in
 * all copies of this software.
 *
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
 * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN
 * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
 * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 *
 * Facebook Author(s): Behdad Esfahbod
 */

#include "hb.hh"
#include "hb-meta.hh"

#include <type_traits>

template <typename T> struct U { typedef T type; };

int
main (int argc, char **argv)
{
  static_assert (hb_is_convertible (void, void), "");
  static_assert (hb_is_convertible (void, const void), "");
  static_assert (hb_is_convertible (const void, void), "");

  static_assert (hb_is_convertible (int,  int), "");
  static_assert (hb_is_convertible (char, int), "");
  static_assert (hb_is_convertible (long, int), "");

  static_assert (hb_is_convertible (int, int), "");

  static_assert (hb_is_convertible (const int, int), "");
  static_assert (hb_is_convertible (int, const int), "");
  static_assert (hb_is_convertible (const int, const int), "");

  static_assert (hb_is_convertible (int&, int), "");
  static_assert (!hb_is_convertible (int, int&), "");

  static_assert (hb_is_convertible (int, const int&), "");
  static_assert (!hb_is_convertible (const int, int&), "");
  static_assert (hb_is_convertible (const int, const int&), "");
  static_assert (hb_is_convertible (int&, const int), "");
  static_assert (hb_is_convertible (const int&, int), "");
  static_assert (hb_is_convertible (const int&, const int), "");
  static_assert (hb_is_convertible (const int&, const int), "");

  struct X {};
  struct Y : X {};

  static_assert (hb_is_convertible (const X &, const X), "");
  static_assert (hb_is_convertible (X &, const X), "");
  static_assert (hb_is_convertible (X &, const X &), "");
  static_assert (hb_is_convertible (X, const X &), "");
  static_assert (hb_is_convertible (const X, const X &), "");
  static_assert (!hb_is_convertible (const X, X &), "");
  static_assert (!hb_is_convertible (X, X &), "");
  static_assert (hb_is_convertible (X &, X &), "");

  static_assert (hb_is_convertible (int&, long), "");
  static_assert (!hb_is_convertible (int&, long&), "");

  static_assert (hb_is_convertible (int *, int *), "");
  static_assert (hb_is_convertible (int *, const int *), "");
  static_assert (!hb_is_convertible (const int *, int *), "");
  static_assert (!hb_is_convertible (int *, long *), "");
  static_assert (hb_is_convertible (int *, void *), "");
  static_assert (!hb_is_convertible (void *, int *), "");

  /* TODO Add more meaningful tests. */

  return 0;
}
