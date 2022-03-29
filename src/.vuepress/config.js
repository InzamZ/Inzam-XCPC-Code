const { description } = require('../../package')

module.exports = {
    /**
     * Ref：https://v1.vuepress.vuejs.org/config/#title
     */
    title: 'InzamZ\'s XCPC Solution',
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
        lastUpdated: true,
        search: false,
        smoothScroll: true,
        algolia: {
            apiKey: '8eba1a9f0dbb348259599150575e76b2',
            indexName: 'acmdocs',
            // If Algolia did not provided you any `appId`, use `BH4D9OD16A` or remove this option
            appId: 'TINIQMJEJ6',
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
            {
                text: 'Languages',
                ariaLabel: 'Language Menu',
                items: [
                    { text: 'Chinese', link: '/language/chinese/' },
                    { text: 'Japanese', link: '/language/japanese/' }
                ]
            }
        ],
        sidebar: {
            '/guide/': [{
                title: 'XCPC题解',
                collapsable: false,
                children: [
                    '',
                    'using-vue',
                ]
            }],
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
                title: 'Guide',
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
    ]
}