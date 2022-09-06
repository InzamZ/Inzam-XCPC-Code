const { description } = require('../../package')

module.exports = {
    /**
     * Ref：https://v1.vuepress.vuejs.org/config/#title
     */
    title: 'InzamZ XCPC Solution',
    /**
     * Ref：https://v1.vuepress.vuejs.org/config/#description
     */
    description: 'Many Solution',

    /**
     * Extra tags to be injected to the page HTML `<head>`
     *
     * ref：https://v1.vuepress.vuejs.org/config/#head
     */
    head: [
        ['meta', { name: 'theme-color', content: '#3eaf7c' }],
        ['meta', { name: 'apple-mobile-web-app-capable', content: 'yes' }],
        ['meta', { name: 'apple-mobile-web-app-status-bar-style', content: 'black' }]
    ],

    locales: {
        // 键名是该语言所属的子路径
        // 作为特例，默认语言可以使用 '/' 作为其路径。
        '/us/': {
            lang: 'en-US', // 将会被设置为 <html> 的 lang 属性
            title: 'InzamZ XCPC Solution',
            description: 'Many Solution'
        },
        '/': {
            lang: 'zh-CN',
            title: 'InzamZ XCPC Solution',
            description: 'Many Solution'
        }
    },
    /**
     * Theme configuration, here is the default theme configuration for VuePress.
     *
     * ref：https://v1.vuepress.vuejs.org/theme/default-theme-config.html
     */
    themeConfig: {
        repo: '',
        editLinks: false,
        docsDir: '',
        editLinkText: '',
        search: false,
        lastUpdated: '最近更新 UTC时间',
        smoothScroll: true,
        algolia: {
            apiKey: 'e268f666983faef92f9e0c4f4cb6209a',
            indexName: 'inzamz',
            // If Algolia did not provided you any `appId`, use `BH4D9OD16A` or remove this option
            appId: 'JTBT5WT94M',
        },
        nav: [{
                text: '题解合集',
                ariaLabel: '题解目录',
                items: [
                    { text: 'Codeforces', link: '/Codeforces/' },
                    { text: 'Atcoder', link: '/Atcoder/' },
                    { text: 'CodeChef', link: '/CodeChef/' },
                    { text: '力扣', link: '/leetcode/' },
                    { text: '其他比赛', link: '/Other/' },
                ]
            },
            {
                text: '学习笔记',
                link: '/note/'
            },
            // {
            //     text: 'RSS',
            //     link: 'rss.xml'
            // }
            // {
            //     text: 'Languages',
            //     ariaLabel: 'Language Menu',
            //     items: [
            //         { text: 'Chinese', link: '/language/chinese/' },
            //         { text: 'Japanese', link: '/language/japanese/' }
            //     ]
            // }
        ],
        sidebar: {
            '/guide/': [{
                    title: 'XCPC题解',
                    collapsable: false,
                    children: [
                        '',
                        'using-vue',
                    ]
                },
                {
                    title: 'Atcoder',
                    collapsable: true,
                    children: [
                        '/Atcoder/ABC182',
                        '/Atcoder/ABC188',
                        '/Atcoder/ABC189',
                        '/Atcoder/ABC244',
                        '/Atcoder/ABC245',
                        '/Atcoder/ABC247',
                        '/Atcoder/ABC250',
                        '/Atcoder/ARC106',
                        '/Atcoder/ARC116',
                        '/Atcoder/ARC147',
                        '/Atcoder/EducationDPContest',
                        '/Atcoder/keyence2021',
                    ]

                },
                {
                    title: 'Codeforces',
                    collapsable: true,
                    children: [
                        '/Codeforces/CF1440_R684',
                        '/Codeforces/CF1451_R685',
                        '/Codeforces/CF1452_EDU98',
                        '/Codeforces/CF1459_R691',
                        '/Codeforces/CF1462_R690',
                        '/Codeforces/CF1463_EDU100',
                        '/Codeforces/CF1609-DR-Aut2021',
                        '/Codeforces/CF1613-Edu118',
                        '/Codeforces/CF1651-Edu124',
                        '/Codeforces/CF1658_R779',
                        '/Codeforces/CF1668_R783',
                        '/Codeforces/CF1671_Edu127',
                        '/Codeforces/CF1675_R787',
                    ]
                },
                {
                    title: 'CodeChef',
                    collapsable: true,
                    children: [
                        '/CodeChef/STARTER39',
                    ]
                },
                {
                    title: '蓝桥杯',
                    collapsable: true,
                    children: [
                        '/Lanqiao/lanqiao2022_regional_CA',
                    ]
                },
                {
                    title: '力扣',
                    collapsable: true,
                    children: [
                        '/Leetcode/LeetCodeCup_2022Spring',
                        '/Leetcode/LeetCodeWeeklyContest291',
                    ]
                },
                {
                    title: '其他比赛',
                    collapsable: true,
                    children: [
                        '/Other/UESTCPC2022',
                    ]
                }
            ],
            '/Atcoder/': [{
                title: 'Atcoder',
                collapsable: false,
                children: [
                    '',
                    'ABC182',
                    'ABC188',
                    'ABC189',
                    'ABC244',
                    'ABC245',
                    'ABC247',
                    'ABC250',
                    'ARC106',
                    'ARC116',
                    'ARC147',
                    'EducationDPContest',
                    'keyence2021',
                ]
            }],
            '/Codeforces/': [{
                title: 'Codeforces',
                collapsable: false,
                children: [
                    '',
                    'CF1440_R684',
                    'CF1451_R685',
                    'CF1452_EDU98',
                    'CF1459_R691',
                    'CF1462_R690',
                    'CF1463_EDU100',
                    'CF1609-DR-Aut2021',
                    'CF1613-Edu118',
                    'CF1651-Edu124',
                    'CF1658_R779',
                    'CF1668_R783',
                    'CF1671_Edu127',
                    'CF1675_R787',
                ]
            }],
            '/CodeChef/': [{
                title: 'CodeChef',
                collapsable: false,
                children: [
                    '',
                    'STARTER39',
                ]
            }],
            '/Lanqiao/': [{
                title: '蓝桥杯',
                collapsable: false,
                children: [
                    'lanqiao2022_regional_CA',
                ]
            }],
            '/Leetcode/': [{
                title: '力扣',
                collapsable: false,
                children: [
                    'LeetCodeCup_2022Spring',
                    'LeetCodeWeeklyContest291',
                ]
            }],
            '/Other/': [{
                title: '其他比赛',
                collapsable: false,
                children: [
                    'UESTCPC2022',
                ]
            }],
            '/Note/': [{
                title: '学习笔记',
                collapsable: false,
                children: [
                    '',
                    'Other/Quicksort',
                    'Other/SortAlgorithm',
                ]
            }]
        },
    },
    /**
     * Apply plugins，ref：https://v1.vuepress.vuejs.org/zh/plugin/
     */
    plugins: [
        '@vuepress/plugin-back-to-top',
        '@vuepress/plugin-medium-zoom',
        '@renovamen/vuepress-plugin-katex',
        "@vuepress/last-updated",
        'sitemap',
        {
            hostname: 'https://acm.inzamz.top'
        },
        '@vuepress/google-analytics',
        {
            'ga': 'G-LD9KGYN8VE' // UA-00000000-0
        }

    ]
}