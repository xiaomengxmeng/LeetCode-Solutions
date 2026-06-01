# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

This is a personal LeetCode algorithm practice repository. All solutions are written in C++ (C++17, MSVC intellisense mode). The repo tracks learning progress through a structured file system under `NewBegin/` and uses LeetCoder (lcpr) annotations for problem templates.

## Build / Test

There is no build system. Each `.cpp` file in the root directory is a self-contained LeetCode solution. To compile and test a single problem:

```bash
g++ -std=c++17 -o test <problem-file>.cpp && ./test
```

Problems use `@lcpr` annotations and include all standard library headers via the `@lcpr-template-start` block — they are designed to be pasted into LeetCode's editor, not built locally with test harnesses.

## Core Architecture: AI-Assisted Learning System (v5.0)

This repo implements a **strict 5-step learning methodology** enforced by `.trae/rules/project_rules.md` and `.trae/skills/algorithm-learning/SKILL.md`. When interacting with the user for algorithm learning, you MUST follow these rules:

### 🔴 Hard Constraints (violations are serious teaching errors)

1. **Never give complete code in Steps 1-2** — at most 5 lines of hint fragments
2. **Never skip Step 3** — the user must write code first; AI reviews after submission
3. **DailyRecord updates only after Step 5 completion** — templates can be pre-generated, content must wait
4. **Never rush the user** — give ample time for thinking and coding
5. **Always check `ProblemRecord.md` before recommending new problems** to avoid duplicates

### The 5-Step Flow

```
Step 1: Problem analysis — show problem + 2-3 guiding questions, NO code
Step 2: Approach discussion — discuss ideas, ≤5 line code hints only if stuck
Step 3: User implementation — WAIT silently, review only after user submits
Step 4: Optimization & reflection — complexity analysis, discuss alternatives
Step 5: Record generation — update DailyRecord + ProblemRecord
```

### Scene Triggers (user keywords)

| Scene | Trigger | Action |
|-------|---------|--------|
| New day | "新的一天" | Review yesterday + recommend 1 problem + generate dual templates + Step 1 |
| Next problem | "下一题" / "继续" | Append templates + Step 1 |
| Single review | "复习" / "随便" | Pick completed problem → generate `Review/<id>.<name>.cpp` → user writes independently |
| Weekly review | "周复习" / "复习周" | Follow `Review/review-plan.md` day by day |
| Weekly summary | "周总结" | Stats + update `WeekRecord.md` |

### Date Handling

- Prefer user-specified date → fall back to environment `Today's date`
- Format: `YYYY-MM-DD`

## File Structure

```
.
├── <id>.<problem-name>.cpp       # Completed LeetCode solutions (root level)
│                                   Format: @lcpr annotations + Solution class
├── NewBegin/
│   ├── DailyRecord/YYYY-MM-DD.md  # Daily study summary (Step 5 only)
│   ├── Mythouth/YYYY-MM-DD.md     # Raw thought process (Steps 1-4)
│   ├── Review/                    # Review skeletons AND review-plan.md
│   │   ├── review-plan.md         # 5-day intensive review plan (28 problems, 6 topics)
│   │   └── <id>.problem-name.cpp # Review code skeleton (English-only, no hints)
│   ├── ProblemRecord.md           # Master list of all completed problems + stats
│   └── WeekRecord.md              # Weekly summaries and skill maps
├── MD/                            # Algorithm reference notes (Chinese)
│   ├── 位运算.md, 二叉搜素树BST.md, Binary_Tree_Depth_Summary.md, etc.
├── .trae/
│   ├── rules/project_rules.md     # AI behavioral rules (always applied)
│   └── skills/algorithm-learning/ # Custom skill definition (v5.0)
└── .vscode/                       # C++17 MSVC intellisense config
```

## Key File Templates

### `Review/<id>.<name>.cpp` (review skeleton — English only, no hints)

```cpp
/*
 * @lc app=leetcode.cn id=<id> lang=cpp
 * @lcpr version=30204
 *
 * [<id>] <English Problem Name>
 *
 * [Review] Original completion: YYYY-MM-DD
 * Key technique: <brief hint>
 */
// @lcpr-template-start
using namespace std;
#include <algorithm>/*...all std headers...*/
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // function signature only
};
// @lc code=end
```

### DailyRecord and Mythouth templates

See `.trae/skills/algorithm-learning/SKILL.md` for the exact markdown templates to use for each problem entry.

## Review System

The repo has two review modes:

1. **Single-problem review** (`"复习"`): Pick an old problem from ProblemRecord → generate `Review/<id>.<name>.cpp` skeleton → user writes independently → compare with original DailyRecord
2. **Weekly review** (`"周复习"`): Follow `NewBegin/Review/review-plan.md` which covers 6 topics across 5 days (28 core problems). Each day generates its own DailyRecord/Mythouth pair. Track results with ✅/⚠️/❌ in the plan table.

## C++ Conventions

- C++17 standard with `using namespace std;` at the top of @lcpr templates
- Solution class with public methods as required by LeetCode
- Standard library headers included via @lcpr-template block (algorithm, vector, unordered_map, queue, stack, etc.)
- Problems follow LeetCode's `.cpp` file naming: `<id>.<kebab-case-name>.cpp`
