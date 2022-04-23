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
            text: 'Guide',
            link: '/guide/',
        },
        {
            text: 'Atcoder',
            link: '/atcoder/'
        },
        {
            text: 'Codeforces',
            link: '/codeforces/'
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
            '/guide/': [
                {
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
                        '/atcoder/ABC182',
                        '/atcoder/ABC188',
                        '/atcoder/ABC189',
                        '/atcoder/ABC244',
                        '/atcoder/ABC245',
                        '/atcoder/ARC106',
                        '/atcoder/ARC116',
                        '/atcoder/EducationDPContest',
                        '/atcoder/keyence2021',
                    ]

                },
                {
                    title: 'Codeforces',
                    collapsable: true,
                    children: [
                        '/codeforces/CF1440_R684',
                        '/codeforces/CF1451_R685',
                        '/codeforces/CF1452_EDU98',
                        '/codeforces/CF1459_R691',
                        '/codeforces/CF1462_R690',
                        '/codeforces/CF1463_EDU100',
                        '/codeforces/CF1609-DR-Aut2021',
                        '/codeforces/CF1613-Edu118',
                        '/codeforces/CF1651-Edu124',
                        '/codeforces/CF1658_R779',
                        '/codeforces/CF1671_Edu127',
                    ]
                },
                {
                    title: '蓝桥杯',
                    collapsable: true,
                    children: [
                        '/lanqiao/lanqiao2022_regional_CA',
                    ]
                },
                {
                    title: '力扣',
                    collapsable: true,
                    children: [
                        '/leetcode/LeetCodeCup_2022Spring',
                    ]
                }
            ],
            '/atcoder/': [{
                title: 'Atcoder',
                collapsable: false,
                children: [
                    '',
                    'ABC182',
                    'ABC188',
                    'ABC189',
                    'ABC244',
                    'ABC245',
                    'ARC106',
                    'ARC116',
                    'EducationDPContest',
                    'keyence2021',
                ]
            }],
            '/codeforces/': [{
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
                    'CF1671_Edu127',
                ]
            }],
            '/lanqiao/': [{
                title: '蓝桥杯',
                collapsable: false,
                children: [
                    'lanqiao2022_regional_CA',
                ]
            }],
            '/leetcode/': [{
                title: '力扣',
                collapsable: false,
                children: [
                    'LeetCodeCup_2022Spring',
                ]
            }],
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
