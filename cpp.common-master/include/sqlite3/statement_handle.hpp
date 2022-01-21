#pragma once

#include "handle.hpp"

#include <sqlite3.h>
#include <cassert>

////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
namespace api::sqlite3 {

  struct statement_handle_traits
  {
    using pointer = ::sqlite3_stmt *;

    static auto invalid() noexcept
    {
      return nullptr;
    }

    static auto close(pointer value) noexcept
    {
      assert(::sqlite3_finalize(value) == SQLITE_OK);
    }
  };

  using statement_handle  
    = utility::handle::unique_handle<statement_handle_traits>;

}

////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////